#include <iostream>

template <int X, int N>
struct pow {
  static const int value = X * pow<X, N - 1>::value;
};

template <int X>
struct pow<X, 0> {
  static const int value = 1;
};

int main() {
  std::cout << pow<5, 5>::value << std::endl;
}