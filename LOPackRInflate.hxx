#pragma once

#include "LOPackRType.hxx"

[[nodiscard]]
[[using gnu : nonnull__ro(1, 2)]]
extern
LOPackRData__Crc32_t
LOPackRInflate__Crc32(
  const
  LOPackRData_t *
  const
    data__inflated,
  LOPackRSize_t
    size__inflated
  );

[[using gnu : nonnull__ro(1, 2)]]
[[using gnu : nonnull__wo(3, 4)]]
extern
void
LOPackRInflate(
  const
  LOPackRData_t *
  const
    data__deflated,
  LOPackRSize_t
    size__deflated,

  LOPackRData_t *
  const
    data__inflated,
  LOPackRSize_t
    size__inflated
  );
