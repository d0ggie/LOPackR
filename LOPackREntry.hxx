#pragma once

#include "LOPackRType.hxx"

#include "LOPackRObject.hxx"
#include "LOPackRStream__DeflatedPayload.hxx"

// Note: The  `.pack'  file consist  of  three major components:  Entry header,
// Entry  and  its Payload stream.  None  of  the components  are  interleaved.
// Storage order (excluding payload) is big endian.
// 0x0000 ... 0x0007: (1) Entry Header (8 bytes)
// 0x0008 ... 0x00??: (N) Entry (12 bytes each), N = pent__n.
// 0x00?? ... 0x????: (N) Payload

[[using gnu : nonnull__rw(1)]]
static
void
LOPackRSwap(
  std::uint32_t *
  const
    data
  ) noexcept
  {
  constexpr
  union
    {
  std::uint32_t
    endian;
  std::uint8_t
    endian__le;
    }
    endian =
    {
   .endian = 1
    };

// Note: Cannot bind packed fields.  So,  these all use pointers.  In  essence,
// all  fields are  big-endian encoded.  Also,  `scalar_storage_order'  is  not
// available on C++ frontend, but that has its limitations anyway.
  if (!!
    endian.endian__le
    ) [[likely]]
 *data = __builtin_bswap32(*data);
  return;
  }

// Note: See ``core/comphelper/source/misc/backupfilehelper.cxx'' for details.
struct
[[using gnu : packed, aligned(4)]]
LOPackREntryHeader
{
// Note: Identity.  This is always ``PACK''.
  LOPackRData__Ident_t
    pack__ident;
// Note: The number of entry headers to follow.  This must be between 1 and 10.
  LOPackRSize_t
    pent__n;
    /* Note: Not enabled.
  LOPackREntry
 a__pent[];
    */
};
static_assert(sizeof(
LOPackREntryHeader)
  == 8);

constexpr
LOPackRData__Ident_t
  pack__ident = "PACK"_u32;
constexpr
LOPackRSize_t
  pent__n__min = 1,
  pent__n__max = 10;

using
  LOPackREntryHeader_t =
LOPackRObject<
  LOPackREntryHeader >;

[[using gnu : nonnull__rw(1)]]
static
void
LOPackRSwap(
  LOPackREntryHeader *
  const
    pack
  ) noexcept
  {
LOPackRSwap(__builtin_addressof(pack->pent__n));
  return;
  }

struct
[[using gnu : packed, aligned(4)]]
LOPackREntry
{
// Note: Filesize, uncompressed.
  LOPackRSize_t
    pent__filesize__full;
// Note: Checksum.  The reference implementation uses this from the compression
// library and so does this.
  LOPackRData__Crc32_t
    pent__crc32;
// Note: Filesize,  compressed.  If both uncompressed and compressed  filesizes
// are  equal  the payload  should be uncompresed.  Is  is  likely possible  to
// craft a compressed stream the size of which is equal to its input.
  LOPackRSize_t
    pent__filesize__pack;
};
static_assert(sizeof(
LOPackREntry)
  == 12);

[[using gnu : nonnull__rw(1)]]
static
void
LOPackRSwap(
  LOPackREntry *
  const
    pent
  ) noexcept
  {
LOPackRSwap(__builtin_addressof(pent->pent__filesize__full));
LOPackRSwap(__builtin_addressof(pent->pent__filesize__pack));
LOPackRSwap(__builtin_addressof(pent->pent__crc32));
  return;
  }

using
  LOPackREntry_t =
LOPackRStream__DeflatedPayload<
  LOPackREntry >;
