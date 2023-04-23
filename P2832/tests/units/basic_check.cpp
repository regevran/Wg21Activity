
#include "../header/P2832.hpp"
#include "catch2/catch_all.hpp"

using Function = void();
using NoexceptFunction = void() noexcept;
using ConstFunction = void() const;
using Array = char[1];
struct Empty {};

TEST_CASE("basic_check")
{
    static_assert(same_as_any_of<int, double, long, int>);
    static_assert(converible_to_any_of<int, double, long>);
    static_assert(converible_to_one_of<int, char*, long>);
    static_assert(converible_to_all_of<int, double, long long, long>);
}

template <class T, class U>
void CheckConvertibleTo() {
    static_assert(std::convertible_to<T, U>);
    static_assert(std::convertible_to<const T, U>);
    static_assert(std::convertible_to<T, const U>);
    static_assert(std::convertible_to<const T, const U>);
}


template <class T, class U>
void CheckNotConvertibleTo() {
    static_assert(!std::convertible_to<T, U>);
    static_assert(!std::convertible_to<const T, U>);
    static_assert(!std::convertible_to<T, const U>);
    static_assert(!std::convertible_to<const T, const U>);
}


template <class T>
constexpr void CommonlyNotConvertibleTo() {
  CheckNotConvertibleTo<T, void>();
  CheckNotConvertibleTo<T, nullptr_t>();
  CheckNotConvertibleTo<T, T*>();
  CheckNotConvertibleTo<T, T Empty::*>();
  CheckNotConvertibleTo<T, T (Empty::*)()>();
  CheckNotConvertibleTo<T, T[sizeof(T)]>();
  CheckNotConvertibleTo<T, T (*)()>();
  CheckNotConvertibleTo<T, T (&)()>();
  CheckNotConvertibleTo<T, T(&&)()>();
}


TEST_CASE("Testing void definitions"){
CheckConvertibleTo<void, void>();
  CheckNotConvertibleTo<void, Function>();
  CheckNotConvertibleTo<void, Function&>();
  CheckNotConvertibleTo<void, Function*>();
  CheckNotConvertibleTo<void, NoexceptFunction>();
  CheckNotConvertibleTo<void, NoexceptFunction&>();
  CheckNotConvertibleTo<void, NoexceptFunction*>();
  CheckNotConvertibleTo<void, Array>();
  CheckNotConvertibleTo<void, Array&>();
  CheckNotConvertibleTo<void, char>();
  CheckNotConvertibleTo<void, char&>();
  CheckNotConvertibleTo<void, char*>();
  CheckNotConvertibleTo<char, void>();
}



