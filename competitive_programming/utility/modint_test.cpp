#include <iostream>


// MOD付き計算だけでもできるように計算は別クラスで
class ModCalcBase 
{
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

// こっちのクラスは値を持つ。operatorを実装しているのでいろいろできる。
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
  operator *(ModCalc& rhs)
  {
    value_type tmp = value;
    mul(tmp, rhs.value);
    return tmp;
  }

  ModCalc&
  operator +=(ModCalc& rhs) 
  {
    add(value, rhs.value);
    return *this;
  }

  ModCalc&
  operator -=(ModCalc& rhs)
  {
    add(value, -rhs.value);
    return *this;
  }

  ModCalc&
  operator *=(ModCalc& rhs)
  {
    mul(value, rhs.value);
    return *this;
  }
};

int main() {
  long long a,b,c;
  a = 10, b = 8, c = 1;

  ModCalc<long long> m1(a), m2(b), m3(c);
  m1 *= m2;
  std::cout << m1() << " " << m2() << "\n";
  m1 -= m2;
  std::cout << m1() << " " << m2() << "\n";
  m1 += m3;
  std::cout << m1() << " " << m2() << "\n";
}
