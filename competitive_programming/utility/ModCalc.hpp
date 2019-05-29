#ifndef _MODCALC_
#define _MODCALC_

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
#endif