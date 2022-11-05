#pragma once

#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <type_traits>
#include <memory>
#include <filesystem>
namespace std__fs = std::filesystem;

#define \
nonnull__ro(_ref_index, ...) \
__nonnull__(_ref_index), __access__(\
  __read_only__, _ref_index \
    __VA_OPT__(,) __VA_ARGS__)
#define \
nonnull__wo(_ref_index, ...) \
__nonnull__(_ref_index), __access__(\
  __write_only__, _ref_index \
    __VA_OPT__(,) __VA_ARGS__)
#define \
nonnull__rw(_ref_index, ...) \
__nonnull__(_ref_index), __access__(\
  __read_write__, _ref_index \
    __VA_OPT__(,) __VA_ARGS__)

#define \
nonnull__return returns_nonnull
