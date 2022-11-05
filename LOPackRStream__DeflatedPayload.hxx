#pragma once

#include "LOPackRType.hxx"
#include "LOPackRObject.hxx"
#include "LOPackRIO.hxx"

template
  <
    typename
     _LOPackRObjectType
  >
struct
LOPackRStream__DeflatedPayload : LOPackRObject< _LOPackRObjectType >
{
  constexpr
  LOPackRStream__DeflatedPayload(
    ) noexcept = default;

  [[nodiscard]]
  LOPackRData_t *
  data__deflatedpayload(
    ) noexcept
    {
    return
  storage__deflatedpayload__ptr();
    }
  [[nodiscard]]
  const
  LOPackRData_t *
  data__deflatedpayload(
    ) const noexcept
    {
    return const_cast< LOPackRStream__DeflatedPayload * >(this)->
  data__deflatedpayload();
    }

  [[nodiscard]]
  LOPackRData_t *
  data(
    ) noexcept
    {
    return
  data__deflatedpayload();
    }


  [[nodiscard]]
  LOPackRSize_t
  size__deflatedpayload(
    ) const noexcept
    {
    return storage__size(
  storage__deflatedpayload());
    }
  [[nodiscard]]
  LOPackRSize_t
  size(
    ) const noexcept
    {
    return
  size__deflatedpayload();
    }


  [[nodiscard]]
  LOPackRData_t *
  data__inflatedpayload(
    ) noexcept
    {
    return
  storage__inflatedpayload__ptr();
    }
  [[nodiscard]]
  const
  LOPackRData_t *
  data__inflatedpayload(
    ) const noexcept
    {
    return const_cast< LOPackRStream__DeflatedPayload * >(this)->
  data__inflatedpayload();
    }

  [[nodiscard]]
  LOPackRSize_t
  size__inflatedpayload(
    ) const noexcept
    {
    return storage__size(
  storage__inflatedpayload());
    }


  void
  storage__deflatedpayload__construct(
    LOPackRSize_t
      size
    )
    {
  storage__deflatedpayload() = storage__construct(
      size);
    }

  void
  storage__inflatedpayload__construct(
    LOPackRSize_t
      size
    )
    {
  storage__inflatedpayload() = storage__construct(
      size);
    }


private:
  [[nodiscard]]
  auto &
  storage__deflatedpayload(
    ) noexcept
    {
    return
    lopackr__deflatedpayload_;
    }
  [[nodiscard]]
  const auto &
  storage__deflatedpayload(
    ) const noexcept
    {
    return const_cast< LOPackRStream__DeflatedPayload * >(this)->
  storage__deflatedpayload();
    }
  [[nodiscard]]
  auto
  storage__deflatedpayload__ptr(
    ) noexcept
    {
    return
  storage__deflatedpayload().get();
    }

  [[nodiscard]]
  auto &
  storage__inflatedpayload(
    ) noexcept
    {
    return
    loback__inflatedpayload_;
    }
  [[nodiscard]]
  const auto &
  storage__inflatedpayload(
    ) const noexcept
    {
    return const_cast< LOPackRStream__DeflatedPayload * >(this)->
  storage__inflatedpayload();
    }

  [[nodiscard]]
  LOPackRData_t *
  storage__inflatedpayload__ptr(
    ) noexcept
    {
    return
  storage__inflatedpayload().get();
    }

  template
    <
      typename
       _TypeT
    >
  struct
__arraysz_delete : std::default_delete< _TypeT [] >
    {
  __arraysz_delete(
      LOPackRSize_t
        size = 0
      ) noexcept
      :
    size_(
      size)
      {
      }

    [[nodiscard]]
    LOPackRSize_t
    size(
      ) const noexcept
      {
      return
    size_;
      }

  private:
    LOPackRSize_t
      size_;
    };

  [[nodiscard]]
  static
  auto
  storage__construct(
    LOPackRSize_t
      size
    )
    {
    return
  std::unique_ptr<
    LOPackRData_t [],
    __arraysz_delete<
    LOPackRData_t > >(new LOPackRData_t [size],
    __arraysz_delete<
    LOPackRData_t >(
      size));
    }

  [[nodiscard]]
  static
  LOPackRSize_t
  storage__size(
    const
    auto &
    __lopackr
    )
    {
    return
    __lopackr ? __lopackr.get_deleter().size() : 0;
    }

  std::unique_ptr<
  LOPackRData_t [],
  __arraysz_delete<
  LOPackRData_t > >
    lopackr__deflatedpayload_ ,
    loback__inflatedpayload_;
};

template
  <
    typename
     _LOPackRObjectType
  >
struct
LOPackRStream__DeflatedPayload__IO :
LOPackRIO<
LOPackRStream__DeflatedPayload< _LOPackRObjectType >
  >
{
  using
   _LOPackRIO =
  LOPackRIO< LOPackRStream__DeflatedPayload< _LOPackRObjectType > >;

  LOPackRStream__DeflatedPayload__IO(
    LOPackRStream__DeflatedPayload<
     _LOPackRObjectType > &
      lopackrstream
    )
    :
 _LOPackRIO(
    lopackrstream)
    {
    }

  [[nodiscard]]
  // virtual
  LOPackRData_t *
  data(
    ) noexcept override
    {
    return reinterpret_cast<
  LOPackRData_t * >(
      this->lopackr().
  data__deflatedpayload());
    }

  [[nodiscard]]
  // virtual
  LOPackRSize_t
  size(
    ) const noexcept override
    {
    return
      this->lopackr().
  size__deflatedpayload();
    }
};

template
  <
    typename
     _LOPackRObjectType
  >
LOPackRStream__DeflatedPayload__IO(
  LOPackRStream__DeflatedPayload<
 _LOPackRObjectType > &
  ) ->
LOPackRStream__DeflatedPayload__IO<
 _LOPackRObjectType
  >;

template
  <
    typename
     _LOPackRObjectType
  >
struct
LOPackRStream__InflatedPayload__IO :
LOPackRIO<
LOPackRStream__DeflatedPayload< _LOPackRObjectType >
  >
{
  using
   _LOPackRIO =
  LOPackRIO< LOPackRStream__DeflatedPayload< _LOPackRObjectType > >;

  LOPackRStream__InflatedPayload__IO(
    LOPackRStream__DeflatedPayload<
     _LOPackRObjectType > &
      lopackrstream
    )
    :
 _LOPackRIO(
    lopackrstream)
    {
    }

  [[nodiscard]]
  // virtual
  LOPackRData_t *
  data(
    ) noexcept override
    {
    return reinterpret_cast<
  LOPackRData_t * >(
    this->lopackr().
  data__inflatedpayload());
    }

  [[nodiscard]]
  // virtual
  LOPackRSize_t
  size(
    ) const noexcept override
    {
    return
      this->lopackr().
  size__inflatedpayload();
    }
};

template
  <
    typename
     _LOPackRObjectType
  >
LOPackRStream__InflatedPayload__IO(
  LOPackRStream__DeflatedPayload<
 _LOPackRObjectType > &
  ) ->
LOPackRStream__InflatedPayload__IO<
 _LOPackRObjectType
  >;
