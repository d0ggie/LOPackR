#pragma once

struct
LOPackRIO__Base
{
protected:
  constexpr
  LOPackRIO__Base(
    ) noexcept = default;
};

template
  <
    typename
     _LOPackRIO
  >
concept
  typename__lopackr__io = std::is_base_of_v<
LOPackRIO__Base, _LOPackRIO >;

template
  <
    typename__lopackr
     _LOPackR
  >
struct
LOPackRIO : LOPackRIO__Base
{
  constexpr
  LOPackRIO(
   _LOPackR &
      lopackr
    ) noexcept
    : lopackr_(lopackr)
    {
    }

  [[nodiscard]]
  virtual
  LOPackRData_t *
  data(
    ) noexcept = 0;

  [[nodiscard]]
  virtual
  const
  LOPackRData_t *
  data(
    ) const noexcept
    {
    return const_cast< LOPackRIO * >(this)->
  data();
    }

  [[nodiscard]]
  virtual
  LOPackRSize_t
  size(
    ) const noexcept = 0;

  virtual
  void
  data__process(
    )
    {
    return;
    }


protected:
 _LOPackR &
  lopackr(
    ) noexcept
    {
    return
  lopackr_;
    }
  const
 _LOPackR &
  lopackr(
    ) const noexcept
    {
    return const_cast< LOPackRIO * >(this)->
  lopackr();
    }

  using
    LOPackRObjectType = typename _LOPackR::
  LOPackRObjectType;


private:
 _LOPackR &
    lopackr_;
};

template
  <
    typename__lopackr
     _LOPackR
  >
LOPackRIO(
 _LOPackR &&
  ) ->
LOPackRIO<
 _LOPackR
  >;

template
  <
    typename__lopackr__io
     _LOPackRIO
  >
struct
LOPackRIO__Peek
{
  constexpr
  LOPackRIO__Peek(
   _LOPackRIO &&
      lopackrio
    ) noexcept
      :
    lopackrio_(
      lopackrio)
    {
    }

  std::istream &
  operator>>(
    std::istream &
   i__stream
    )
    {
   _LOPackRIO &
    __lopackrio =
    lopackrio();

    peek(
   i__stream,
    __lopackrio.data(),
    __lopackrio.size());
    __lopackrio.data__process();
    return
   i__stream;
    }

private:
  void
  peek(
    std::istream &
 i__stream,

    LOPackRData_t *
    const
      data,
    LOPackRSize_t
      size
    )
    {
    if (!
      data
      ) [[unlikely]]
bail__failure:
      throw std::runtime_error(streamize()
        << "peek failed: `"
          << hilight(reinterpret_cast< const void * >(
      data))
        << ":"
          << hilight__hex(
      size) << "'");
    else
    if (!
      size
      ) [[unlikely]]
      goto bail__failure;

 i__stream.read(
    reinterpret_cast< char * >(
      data),
      size);
    if (!
 i__stream.good()
      )
      goto bail__failure;

    return;
    }

 _LOPackRIO &
  lopackrio(
    ) noexcept
    {
    return
  lopackrio_;
    }

 _LOPackRIO
    lopackrio_;
};

template
  <
    typename__lopackr__io
     _LOPackRIO
  >
LOPackRIO__Peek(
 _LOPackRIO &&
  ) ->
LOPackRIO__Peek<
 _LOPackRIO
  >;

template
  <
    typename__lopackr__io
     _LOPackRIO
  >
std::istream &
operator>>(
  std::istream &
 i__stream,
  LOPackRIO__Peek<
   _LOPackRIO > &&
    lopackr__peek
  )
  {
  return
    lopackr__peek >>
 i__stream;
  }

template
  <
    typename__lopackr__io
     _LOPackRIO
  >
struct
LOPackRIO__Poke
{
  constexpr
  LOPackRIO__Poke(
   _LOPackRIO &&
      lopackrio
    ) noexcept
      :
    lopackrio_(
      lopackrio)
    {
    }

  std::ostream &
  operator<<(
    std::ostream &
   i__stream
    )
    {
   _LOPackRIO &
    __lopackrio =
    lopackrio();

    poke(
   i__stream,
    __lopackrio.data(),
    __lopackrio.size());
    return
   i__stream;
    }

private:
  void
  poke(
    std::ostream &
 i__stream,

    const
    LOPackRData_t *
    const
      data,
    LOPackRSize_t
      size
    )
    {
    if (!
      data
      ) [[unlikely]]
bail__failure:
      throw std::runtime_error(streamize()
        << "poke failed: `"
          << hilight(reinterpret_cast< const void * >(
      data))
        << ":"
          << hilight__hex(
      size) << "'");
    else
    if (!
      size
      ) [[unlikely]]
      goto bail__failure;

 i__stream.write(
    reinterpret_cast< const char * >(
      data),
      size);
    if (!
 i__stream.good()
      )
      goto bail__failure;

    return;
    }

 _LOPackRIO &
  lopackrio(
    ) noexcept
    {
    return
  lopackrio_;
    }

 _LOPackRIO
    lopackrio_;
};

template
  <
    typename__lopackr__io
     _LOPackRIO
  >
LOPackRIO__Poke(
 _LOPackRIO &&
  ) ->
LOPackRIO__Poke<
 _LOPackRIO
  >;

template
  <
    typename__lopackr__io
     _LOPackRIO
  >
std::ostream &
operator<<(
  std::ostream &
 i__stream,
  LOPackRIO__Poke<
   _LOPackRIO > &&
    lopackr__poke
  )
  {
  return
    lopackr__poke <<
 i__stream;
  }
