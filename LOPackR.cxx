// ============================================================================
//   LOPACK'D -- READ (AND INFLATE) LIBREOFFICE `.PACK' BACKUP FILES
// ----------------------------------------------------------------------------
// Public domain, if used for good.  If that does not work for you, well, tough
// luck.  Should be feature complete what comes to `.pack' file handling.

#include "LOPackR__Common.hxx"
#include "LOPackRUtility.hxx"

#include "LOPackR.hxx"
#include "LOPackREntry.hxx"

#include "LOPackRInflate.hxx"

static
void
LOPackR__File(
  const
  std__fs::path &
    pack__path
  )
  {
  std::cout
    << "`"
      << hilight(
    pack__path.filename())
    << "'\n\t(@ ``"
      << hilight(
    pack__path)
    << "'')." <<
  std::endl
    ;

  std::ifstream
if__pack;
if__pack.open(
    pack__path, std::ios_base::binary);
  if (!
if__pack
    ) [[unlikely]]
    throw std::runtime_error(streamize()
      << "unable to open `"
        << hilight(
    pack__path)
      << "'");

  LOPackREntryHeader_t
    pack;

if__pack >> LOPackRIO__Peek(LOPackRObject__IO(
    pack));

  if (
    pack->pack__ident != pack__ident
    ) [[unlikely]]
    throw std::runtime_error(streamize()
      << "corrupt file: unexpected identity `"
        << hilight__hex(
    pack->pack__ident)
      << "'");

  std::vector<
  LOPackREntry_t >
 v__pent;

#ifdef MOREOUTPUT
  std::cout
    << "`"
      << pack__path.filename()
    << "'," "\n\t" "number of entries `"
      << hilight__dec(pack->pent__n)
    << "'." <<
  std::endl
#endif // ..
    ;

  if (
    pack->pent__n < pent__n__min
      ||
    pack->pent__n > pent__n__max
    ) [[unlikely]]
    throw std::runtime_error(streamize()
      << "corrupt file: unexpected number of entries `"
        << hilight__dec(
    pack->pent__n)
      << "'");

 v__pent.reserve(
    pack->pent__n);

  for (std::uint32_t
    pent__n = 0;
    pent__n <
    pack->pent__n;
  ++pent__n)
    {
  LOPackREntry_t
    pent;

if__pack >> LOPackRIO__Peek(LOPackRObject__IO(
    pent));

  std::cout
    << "`"
      << pack__path.filename()
    << "'," "\n\t" "entry #"
      << hilight__dec(pent__n + 1)
    << " / "
      << pack->pent__n
    << "\n\t\t" "inflated size `"
      << std::setw(8) << std::setfill(' ')
      << hilight__dec(
    pent->pent__filesize__full)
    << "',\n\t\t" "deflated size `"
      << std::setw(8) << std::setfill(' ')
      << hilight__dec(
    pent->pent__filesize__pack)
    << "', crc32 `"
      << std::setw(8) << std::setfill('0')
      << hilight__hex(
    pent->pent__crc32)
    << "'." <<
  std::endl
    ;

 v__pent.push_back(std::move(
    pent));
    }

  for (std::uint32_t
    pent__n = 0;
    pent__n <
    pack->pent__n;
  ++pent__n)
    {
  LOPackREntry_t &
    pent =
 v__pent.at(
    pent__n);

  if (!
    pent->pent__filesize__pack
    ) [[unlikely]]
    {
  if (!!
    pent->pent__filesize__full
    ) [[unlikely]]
    throw std::runtime_error(streamize()
      << "corrupt file: inflated size `"
        << hilight__dec(
    pent->pent__filesize__full)
      << "' without deflated data");

    continue;
    }

  pent.storage__inflatedpayload__construct(
    pent->pent__filesize__full);

// Note: Especially  for  very small files deflated size could be  larger  than
// inflated size.  This seems to be nothing out of ordinary.  Only if the sizes
// are truly equal then there should be no compression.
  if (
    pent.size__deflatedpayload()
      !=
    pent.size__inflatedpayload()
    ) [[likely]]
    {
  pent.storage__deflatedpayload__construct(
    pent->pent__filesize__pack);
if__pack >> LOPackRIO__Peek(LOPackRStream__DeflatedPayload__IO(
    pent));
  LOPackRInflate(
    pent.data__deflatedpayload(),
    pent.size__deflatedpayload(),
    pent.data__inflatedpayload(),
    pent.size__inflatedpayload());
    }
  else
if__pack >> LOPackRIO__Peek(LOPackRStream__InflatedPayload__IO(
    pent));

  if (
  const
  LOPackRData__Crc32_t
    pent__crc32__computed =
  LOPackRInflate__Crc32(
    pent.data__inflatedpayload(),
    pent.size__inflatedpayload());
    pent->pent__crc32 != pent__crc32__computed
    ) [[unlikely]]
    throw std::runtime_error(streamize()
      << "corrupt file: checksum mismatch, expected `"
        << std::setw(8) << std::setfill('0')
        << hilight__hex(
    pent->pent__crc32)
      << "' but got `"
        << std::setw(8) << std::setfill('0')
        << hilight__hex(
    pent__crc32__computed)
      << "'");

  std__fs::path
    full__path =
    pack__path;
  const
  std::string
    full__path__extension = (streamize()
    << "full__"
      << std::setfill('0') << std::setw(2) << std::dec
      << pent__n).as_string();
  full__path.replace_extension(
  full__path__extension);

  if (!
    pent->pent__filesize__full
    ) [[unlikely]]
    continue;

  std::ofstream
of__full;
of__full.open(
    full__path, std::ios_base::binary);
  if (!
of__full
    ) [[unlikely]]
    throw std::runtime_error(streamize()
      << "unable to open `"
        << hilight(
    full__path)
      << "'");


of__full << LOPackRIO__Poke(LOPackRStream__InflatedPayload__IO(
    pent));
of__full.close();

  std::cout
    << "`"
      << hilight(
    full__path.filename())
    << "'\n\t(@ ``"
      << hilight(
    full__path)
    << "'')." <<
  std::endl
    ;
    }

  return;
  }

int
main(
  int
    argc,
  char **
    argv
  )
  {
  int
    retc = EXIT_FAILURE;
  try
    {
  if (
    argc < 2
    ) [[unlikely]]
    throw std::runtime_error(
      "no file(s) given");

  for (int
    argv__n = 1;
    argv__n <
    argc;
  ++argv__n)
    {
    std__fs::path
      pack__path(argv[argv__n]);
    pack__path.make_preferred();
    LOPackR__File(
      pack__path);
    }

    retc = EXIT_SUCCESS;
    }
  catch (
    std::exception &
      what
    )
    {
    std::cerr
      << "oops: ``"
        << what.what()
      << "''." <<
    std::endl
      ;
    }
  catch (...)
    {
    std::cerr
      << "oops?" <<
    std::endl
      ;
    }

  return
    retc;
  }
