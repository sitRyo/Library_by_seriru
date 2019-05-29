#include <iostream>

class ModCalc {
  using mod_type = long long;

  mod_type M = 1000000007;
public:
  
  template <class Reference, class Body>
  void add(Reference& lval, Body body) const noexcept
  {
    lval += body % M;
    lval %= M;
  }

  template <class Reference, class Thead, class ...Args>
  void add(Reference& lval, Thead head, Args... body) const noexcept
  {
    lval += head % M;
    lval %= M;
    add(lval, body...);
  }

  template <class Reference, class Body>
  void mul(Reference& lval, Body body) const noexcept
  {
    lval *= body % M;
    lval %= M;
  }

  template <class Reference, class Thead, class ...Args>
  void mul(Reference& lval, Thead head, Args... body) const noexcept
  {
    lval *= head % M;
    lval %= M;
    mul(lval, body...);
  }
};

int main() {
  long long a,b,c;
  a = 10e9, b = 8, c = 1;

  ModCalc m;
  m.add(a,b,c);

  a = 23487; b = 141324895; c = 1495837;
  m.mul(a, b, c);

  if (a > 10e9 + 8) {
    return 0;
  }
  
  std::cout << a << "\n";
}
