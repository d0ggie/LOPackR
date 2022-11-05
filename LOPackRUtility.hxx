#pragma once

[[nodiscard]]
constexpr
std::uint32_t
operator "" _u32 (
  const
  char *
  const
    text,
  std::size_t
    size
  ) noexcept
  {
  std::uint32_t
    data = 0;
  for (unsigned n = 0; n < std::min(sizeof(data), size); ++n)
    data += text[n] << (n << 3);
  return
    data;
  }

template
  <
    typename
     _Func
  >
struct
scoped_exit
{
  constexpr
  scoped_exit(
   _Func &&
      func
    ) noexcept
    :
    func_(
      func)
    {
    }

 ~scoped_exit(
    ) noexcept
    {
    func_();
    }


private:
 _Func
    func_;
};

template
  <
    typename
     _Func
  >
scoped_exit(
  _Func &&
  ) ->
scoped_exit<
 _Func >;

template
  <
    typename
     _Type
  >
struct
hilight
{
  constexpr
  hilight(
    const
   _Type &
      type
    )
    :
  type_(
    type)
    {
    }

  void
  operator<<(
    std::ostream &
   o__stream
    )
    {
    const
    std::streamsize
   o__stream__width =
   o__stream.width(0);
   o__stream
      << "\e[1m" << std::setw(
  o__stream__width)
        << type_
      << "\e[0m";
    return;
    }


private:
  const
 _Type &
    type_;
};

template
  <
    typename
     _Type
  >
hilight(
  const
 _Type &
  ) ->
hilight<
 _Type >;

template
  <
    typename
     _Type
  >
struct
hilight__fmt : hilight< _Type >
{
  template
    <
      typename...
       _Args
    >
  constexpr
  hilight__fmt(
    std::ios_base::fmtflags
      fmtflags,
   _Args &&...
      args
    )
    :
  hilight<
   _Type >(
    std::forward< _Args >(
      args)...),

  fmtflags_(
    fmtflags),
  fmtflags__field_(
  fmtflags__field(
    fmtflags))
    {
    }

  void
  operator<<(
    std::ostream &
   o__stream
    )
    {
    struct
  __fmtflags__save
    {
    __fmtflags__save(
        std::ostream &
       o__stream
        ) noexcept
        :
     o__stream_(
     o__stream),
        stream__fmtflags_(
     o__stream_.flags())
        {
        }

   ~__fmtflags__save(
        ) noexcept
        {
     o__stream_.setf(
        stream__fmtflags_);
        }


    private:
      std::ostream &
     o__stream_;
      std::ios_base::fmtflags
        stream__fmtflags_;
    };

  __fmtflags__save
  __o__stream__fmtflags(
    o__stream);

    if (!!
      fmtflags__field_
      )
   o__stream.setf(
      fmtflags_,
      fmtflags__field_);
    else
   o__stream.setf(
      fmtflags_);

    static_cast< hilight< _Type > * >(this)->operator<<(
   o__stream);

    return;
    }


private:
  [[nodiscard]]
  static
  constexpr
  std::ios_base::fmtflags
  fmtflags__field(
    std::ios_base::fmtflags
      fmtflags
    ) noexcept
    {
    constexpr
    std::ios_base::fmtflags
  a__fmtflags__field[] = {
    std::ios_base::adjustfield,
    std::ios_base::basefield,
    std::ios_base::floatfield
    };
    constexpr
    std::ios_base::fmtflags
      fmtflags__field__0 = static_cast<
    std::ios_base::fmtflags >(0);
    for (const auto &
      fmtflags__field :
   a__fmtflags__field)
    if (!!
     (fmtflags__field &
      fmtflags)
      )
    return
      fmtflags__field;

    return
      fmtflags__field__0;
    }

  std::ios_base::fmtflags
    fmtflags_,
    fmtflags__field_;
};


template
  <
    typename
     _Type
  >
struct
hilight__hex : hilight__fmt< _Type >
{
  constexpr
  hilight__hex(
    const
   _Type &
      type
    ) :
  hilight__fmt<
   _Type >(std::ios_base::hex,
      type)
    {
    }
};

template
  <
    typename
     _Type
  >
hilight__hex(
  const
 _Type &
  ) ->
hilight__hex<
 _Type >;

template
  <
    typename
     _Type
  >
struct
hilight__dec : hilight__fmt< _Type >
{
  constexpr
  hilight__dec(
    const
   _Type &
      type
    ) :
  hilight__fmt<
   _Type >(std::ios_base::dec,
      type)
    {
    }
};

template
  <
    typename
     _Type
  >
hilight__dec(
  const
 _Type &
  ) ->
hilight__dec<
 _Type >;

template
  <
    typename
     _Type
  >
std::ostream &
operator<<(
  std::ostream &
 o__stream,
  hilight< _Type >
    hilight
  )
  {
  hilight <<
 o__stream;
  return
 o__stream;
  }

template
  <
    typename
     _Type
  >
std::ostream &
operator<<(
  std::ostream &
 o__stream,
  hilight__fmt< _Type >
    hilight
  )
  {
  hilight <<
 o__stream;
  return
 o__stream;
  }

struct
streamize
{
  streamize(
    ) noexcept = default;

  [[nodiscard]]
  std::string
  as_string(
    ) const noexcept
    {
    return
 o__stringstream_.str();
    }

  template
    <
      typename
       _TypeT
    >
  streamize &
  operator<<(
    const
   _TypeT &
      type
    )
    {
 o__stringstream_ <<
      type;
    return *this;
    }

  [[nodiscard]]
  explicit
  operator
  std::string (
    ) const
    {
    return
    as_string();
    }

  [[nodiscard]]
  operator
  const
  char * (
    ) const
    {
 o__stringstream__copy_ = as_string();
    return
 o__stringstream__copy_.c_str();
    }


private:
  mutable
  std::string
 o__stringstream__copy_;
  std::ostringstream
 o__stringstream_;
};
