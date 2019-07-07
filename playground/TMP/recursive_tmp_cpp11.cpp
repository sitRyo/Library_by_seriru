#include <iostream>
#include <utility>

// 再帰処理を使用して、T型の変数にN個のポインタを付与するメタ関数

template <int N> struct int_ {};
template <bool cond> struct bool_ {};

// tag despatch
struct cont {}; // continue
struct end {}; // end

template < bool Cond >
auto is_end (bool_<Cond>)
-> typename std::conditional<Cond, end, cont>::type;

template < class T, int N >
auto add_pointers_impl( T, int_<N>, cont )
-> decltype(
  add_pointers_impl(
    std::declval<T*>(),
    int_<N - 1>(),
    std::declval<
    decltype(
      is_end( bool_<N - 1 == 0>() 
      )
    )>()
  )
);

template < class T, int N >
auto add_pointers_impl( T, int_<N>, end )
-> T;

template < class T, int N >
auto add_pointers( T, int_<N> )
-> decltype(
  add_pointers_impl (
    std::declval<T>(),
    int_<N>(),
    std::declval<
    decltype(
      is_end( bool_<N == 0>() )
    )
  >()
  )
);

template < class T, int N >
using pow_pointer = decltype(
  add_pointers(
    std::declval<T>(),
    int_<N>()
  )
);

int main() {
  int* p;
  pow_pointer< int, 2 > dp = &p;
}