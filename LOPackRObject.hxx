#pragma once

#include "LOPackRType.hxx"
#include "LOPackRIO.hxx"

template
  <
    typename
     _LOPackRObjectType
  >
struct
LOPackRObject : LOPackR__Base
{
  using
    LOPackRObjectType =
 _LOPackRObjectType;

  LOPackRObject(
    ) noexcept = default;

  [[nodiscard]]
 _LOPackRObjectType &
  data__ref(
    ) noexcept
    {
    return
    lopackr_;
    }
  [[nodiscard]]
  const
 _LOPackRObjectType &
  data__ref(
    ) const noexcept
    {
    return const_cast< LOPackRObject * >(this)->
  data__ref();
    }

  [[nodiscard]]
  [[using gnu : nonnull__return]]
 _LOPackRObjectType *
  data(
    ) noexcept
    {
    return std::addressof(
  data__ref());
    }

  [[nodiscard]]
  [[using gnu : nonnull__return]]
 _LOPackRObjectType *
  operator&(
    ) noexcept
    {
    return
  data();
    }


  [[nodiscard]]
  [[using gnu : nonnull__return]]
  const
 _LOPackRObjectType *
  data(
    ) const noexcept
    {
    return const_cast< LOPackRObject * >(this)->
  data();
    }

  [[nodiscard]]
  constexpr
  LOPackRSize_t
  size(
    ) const noexcept
    {
    return sizeof(
    lopackr_);
    }

  [[nodiscard]]
  [[using gnu : nonnull__return]]
 _LOPackRObjectType *
  operator->(
    ) noexcept
    {
    return
  data();
    }


private:
 _LOPackRObjectType
    lopackr_;
};

template
  <
    typename
     _LOPackRObjectType
  >
struct
LOPackRObject__IO :
LOPackRIO<
LOPackRObject< _LOPackRObjectType >
  >
{
  using
   _LOPackRIO =
  LOPackRIO< LOPackRObject< _LOPackRObjectType > >;

  LOPackRObject__IO(
    LOPackRObject<
     _LOPackRObjectType > &
      lopackrobject
    )
    :
 _LOPackRIO(lopackrobject)
    {
    }

  [[nodiscard]]
  [[using gnu : nonnull__return]]
  // virtual
  LOPackRData_t *
  data(
    ) noexcept override
    {
    return reinterpret_cast<
  LOPackRData_t * >(
      this->lopackr().
  data());
    }

  [[nodiscard]]
  // virtual
  LOPackRSize_t
  size(
    ) const noexcept override
    {
    return
      this->lopackr().
  size();
    }

  // virtual
  void
  data__process(
    )
    {
    LOPackRSwap(
      this->lopackr().
  data());
    }
};

template
  <
    typename
     _LOPackRObjectType
  >
LOPackRObject__IO(
  LOPackRObject<
 _LOPackRObjectType > &
  ) ->
LOPackRObject__IO<
 _LOPackRObjectType
  >;
