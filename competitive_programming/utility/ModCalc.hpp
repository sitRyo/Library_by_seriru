#ifndef _MODCALC_
#define _MODCALC_

#include <iostream>

/* CUT CUT CUT */
// MOD付き計算だけでもできるように計算は別クラスで
// static付き
class ModCalcBase 
{
  using mod_type = long long;

  static constexpr mod_type M = 1000000007;
public:
  
  template <class Reference, class Body>
  static void add(Reference& lval, Body body) noexcept
  {
    lval += body % M;
    lval %= M;
  }

  template <class Reference, class Thead, class ...Args>
  static void add(Reference& lval, Thead head, Args... body) noexcept
  {
    lval += head % M;
    lval %= M;
    add(lval, body...);
  }

  template <class Reference, class Body>
  static void mul(Reference& lval, Body body) noexcept
  {
    lval *= body % M;
    lval %= M;
  }

  template <class Reference, class Thead, class ...Args>
  static void mul(Reference& lval, Thead head, Args... body) noexcept
  {
    lval *= head % M;
    lval %= M;
    mul(lval, body...);
  }
};

/* END END END */

// こっちのクラスは値を持つ。operatorをoverloadしているのでいろいろできる。
template <class T>
class ModCalc : public ModCalcBase 
{
  using value_type = T;
  using reference = value_type&;
public:
  value_type value;
  
  ModCalc(value_type value = 0)
    : value(value) {}

  // 値の変更はメソッドを使って欲しい。。。
  value_type
  operator ()() const
  {
    return value;
  }

  value_type
  operator +(ModCalc& rhs) const noexcept
  {
    value_type tmp = value;
    add(tmp, rhs.value);
    return tmp;
  }

  value_type
  operator -(ModCalc& rhs) const noexcept
  {
    value_type tmp = value;
    add(tmp, -rhs.value);
    return tmp;
  }

  value_type 
  operator *(ModCalc& rhs) const noexcept
  {
    value_type tmp = value;
    mul(tmp, rhs.value);
    return tmp;
  }

  ModCalc&
  operator +=(ModCalc& rhs) noexcept
  {
    add(value, rhs.value);
    return *this;
  }

  ModCalc&
  operator -=(ModCalc& rhs) noexcept
  {
    add(value, -rhs.value);
    return *this;
  }

  ModCalc&
  operator *=(ModCalc& rhs) noexcept
  {
    mul(value, rhs.value);
    return *this;
  }
};

#endif