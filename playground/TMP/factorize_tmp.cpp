#include <iostream>

template <int N>
struct factorize {
  static const int value = N * factorize<N - 1>::value;
};

// 明示的特殊化(再帰の終了条件)
template <>
struct factorize<0> {
  static const int value = 1;
};

int main() {
  int result = factorize<7>::value;
  std::cout << result << std::endl;
}