#include <utility>
#include <array>

template <int... Is> // when called below, Is will be 0 - N
constexpr std::array<int, sizeof...(Is)> make_inc_array_impl(
    std::integer_sequence<int, Is...>) {
  return {{(Is + 1)...}}; // +1 to start at one instead of [0, 1, ...]
}


template <std::size_t N>
constexpr std::array<int, N> make_inc_array() {
  return make_inc_array_impl(std::make_integer_sequence<int, N>{});
}