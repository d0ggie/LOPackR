#pragma once

#include <zlib.h>
#define compress(symbol) z_ ## symbol
#define COMPRESS(SYMBOL) Z_ ## SYMBOL
using CompressRetC_t = int;

template
  <
    typename...
     _Args__Compress,
    typename...
     _Args
  >
[[nodiscard]]
CompressRetC_t
Compress(
  CompressRetC_t (*
    comp__api)(
   _Args__Compress...),
  const
  char *
  const
    comp__apiname,
 _Args &&...
    args...
  ) noexcept
requires
  (
  std::is_convertible_v<
   _Args__Compress,
   _Args > && ...
  )
  {
  const
  CompressRetC_t
    comp__retc =
  comp__api(std::forward< _Args >(args)...);
  if (
    comp__retc < COMPRESS(OK)
    ) [[unlikely]]
    std::cerr
      << "compress `"
        << hilight(
    comp__apiname ?: "unknown")
      << "' failed: `"
        << hilight__dec(
    comp__retc)
      << "'" << std::endl;
#if defined(\
COMPRESS_DEBUG) \
 && \
COMPRESS_DEBUG
  else
    std::cout
      << "compress `"
        << hilight(
    comp__apiname ?: "unknown")
      << "': " << comp__retc << std::endl;
#endif /*
COMPRESS_DEBUG */
  return
    comp__retc;
  }

#define \
Compress( \
 _compress, ... \
  ) \
Compress( \
 _compress, #_compress \
__VA_OPT__(,) __VA_ARGS__)

// Note: Sorry.
#define \
Compress__InflateInit( \
 _compress__stream, ... \
  ) \
Compress(inflateInit_, \
 _compress__stream, \
    static_cast< const char * >(ZLIB_VERSION), \
    static_cast< int >(sizeof(compress(stream))) \
__VA_OPT__(,) __VA_ARGS__)
#define \
Compress__Inflate( \
 _compress__stream, ... \
  ) \
Compress(inflate, \
 _compress__stream \
__VA_OPT__(,) __VA_ARGS__)
#define \
Compress__InflateFini( \
 _compress__stream, ... \
  ) \
Compress(inflateEnd, \
 _compress__stream \
__VA_OPT__(,) __VA_ARGS__)
