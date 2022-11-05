#pragma once

struct
LOPackR__Base
{
protected:
  LOPackR__Base(
    ) noexcept = default;
};

template
  <
    typename
     _LOPackRObjectType
  >
concept
    typename__lopackr = std::is_base_of_v<
LOPackR__Base, _LOPackRObjectType >;
