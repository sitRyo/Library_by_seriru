#include <iostream>

struct Hoge {
  static void foo() {
    std::cout << "Hoge" << std::endl;
  }
};

struct Fuga {
  static void foo() {
    std::cout << "Fuga" << std::endl;
  }
};

template <class Policy>
struct Dispatcher {
  constexpr void do_something() {
    Policy::foo();
  }
};

int main() {
  Dispatcher<Fuga> fuga;
  Dispatcher<Hoge> hoge;
  
  fuga.do_something();
  hoge.do_something();
}