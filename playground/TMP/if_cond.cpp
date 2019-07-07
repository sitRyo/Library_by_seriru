#include <iostream>

template <bool Cond, class Then, class Else>
struct if_c;

template <class Then, class Else>
struct if_c<true, Then, Else>
{
  typedef Then type;
};

template <class Then, class Else>
struct if_c<false, Then, Else>
{
  typedef Else type
};

template <class Cond, class Then, class Else>
struct if_ : public if_c<Cond::value, Then, Else> {};

template <int N>
struct is_even {
  static constexpr bool value = N % 2 == 0;
};

int main() {
  if_<is_even<2>, int, double>::type p;
}