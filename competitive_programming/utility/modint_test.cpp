#include <iostream>

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
    lval += (Reference)body % M;
    lval %= M;
  }

  template <class Reference, class Thead, class ...Args>
  static void add(Reference& lval, Thead head, Args... body) noexcept
  {
    lval += (Reference)head % M;
    lval %= M;
    add(lval, body...);
  }

  template <class Reference, class Body>
  static void mul(Reference& lval, Body body) noexcept
  {
    lval *= (Reference)body % M;
    lval %= M;
  }

  template <class Reference, class Thead, class ...Args>
  static void mul(Reference& lval, Thead head, Args... body) noexcept
  {
    lval *= (Reference)head % M;
    lval %= M;
    mul(lval, body...);
  }

  // 返り値が負数になってはいけない
  template <class Reference, class Body>
  static void sub(Reference& lval, Body body) noexcept
  {
    lval -= (Reference)body % M;
    lval += M;
    lval %= M;
  }

  template <class Reference, class Thead, class ...Args>
  static void sub(Reference& lval, Thead head, Args... body) noexcept
  {
    lval -= (Reference)head % M;
    lval += M;
    lval %= M;
    sub(lval, body...);
  }
};

// こっちのクラスは値を持つ。operatorを実装しているのでいろいろできる。
class ModCalc : public ModCalcBase 
{
  using value_type = long long;
  using reference = value_type&;
public:
  value_type value;
  
  ModCalc(value_type value = 0)
    : value(value) {}

  const value_type&
  operator ()() const
  {
    return value;
  }

  value_type
  operator +(const ModCalc& rhs) const noexcept
  {
    value_type tmp = value;
    add(tmp, rhs.value);
    return tmp;
  }

  value_type
  operator -(const ModCalc& rhs) const noexcept
  {
    value_type tmp = value;
    sub(tmp, rhs.value);
    return tmp;
  }

  value_type 
  operator *(const ModCalc& rhs) const noexcept
  {
    value_type tmp = value;
    mul(tmp, rhs.value);
    return tmp;
  }
    
  ModCalc&
  operator +=(const ModCalc& rhs) noexcept
  {
    add(value, rhs.value);
    return *this;
  }

  ModCalc&
  operator -=(const ModCalc& rhs) noexcept
  {
    sub(value, rhs.value);
    return *this;
  }

  ModCalc&
  operator *=(const ModCalc& rhs) noexcept
  {
    mul(value, rhs.value);
    return *this;
  }

  friend std::ostream& operator <<(std::ostream& os, const ModCalc& rhs);
};

std::ostream& operator <<(std::ostream& os, const ModCalc& rhs)
{
  os << rhs();
  return os;
}

using std::cout;
using std::endl;
/*
int main() {
  long long a,b,c,d;
  a = 1, b = 2, c = 3, d = 4;
  ModCalcBase::add(a, b, c, d);
  cout << a << endl; // 10
  ModCalcBase::sub(a, b, c);
  cout << a << endl; // 5
  ModCalcBase::mul(a, b);
  cout << a << endl; // 10

  a = 1000000006, b = 2;
  ModCalcBase::add(a, b);
  cout << a << endl; // 1
  a = 4000000010, b = 1000000006, c = 2000000000;
  ModCalcBase::sub(a, c, b);
  cout << a << endl; // 1000000004
  a = 1000000006, b = 2;
  ModCalcBase::mul(a, b);
  cout << a << endl; // 1000000005
}
*/

int main() {
  long long a,b,c,d;
  a = 1, b = 2, c = 3, d = 4;

  ModCalc ins1(a), ins2(b), ins3(c);
  cout << ins1 + ins2 << endl; // 3
  cout << ins2 - ins1 << endl; // 1
  cout << ins2 * ins1 << endl; // 2

  ins1 += ins2;
  cout << ins1 << endl; // 3
  ins1 -= ins2;
  cout << ins1 << endl; // 1
  ins1 *= ins3;
  cout << ins3 << endl; // 3
}