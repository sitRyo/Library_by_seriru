#include <iostream>
using std::cout;
using std::endl;

template < typename T >
struct intLike { 
  using value = T;
  using reference = T &;

  value data;
  
  intLike () {}
  intLike (value p) : data(p) {}

  intLike
  const operator +(intLike & obj) const noexcept
  {
    return intLike(data + obj.data);
  }

  intLike
  const operator -(intLike & obj) const noexcept
  {
    return intLike(data - obj.data);
  }

  intLike &
  operator ++() noexcept
  {
    ++data;
    return *this;
  }

  intLike
  const operator ++(value) noexcept
  {
    auto temp = *this;
    ++*this;
    return temp;
  }

  intLike &
  operator --()
  {
    --data;
    return *this;
  }

  intLike 
  operator --(value) noexcept
  {
    auto temp = *this;
    --*this;
    return temp;
  }

  intLike &
  operator *=(intLike const & n)
  {
    data *= n.data;
    return *this;
  }

  intLike &
  operator /=(intLike const & n)
  {
    data /= n.data;
    return *this;
  }

  intLike &
  operator %=(intLike const & n)
  {
    data %= n.data;
    return *this;
  }

  intLike &
  operator +=(intLike const & n)
  {
    data += n.data;
    return *this;
  }

  intLike &
  operator -=(intLike const & n)
  {
    data -= n.data;
    return *this;
  }

  intLike &
  operator <<=(intLike const & n)
  {
    data <<= n.data;
    return *this;
  }

  intLike &
  operator >>=(intLike const & n)
  {
    data >>= n.data;
    return *this;
  }

  intLike &
  operator &=(intLike const & n)
  {
    data &= n.data;
    return *this;
  }

  intLike &
  operator |=(intLike const & n)
  {
    data |= n.data;
    return *this;
  }

  intLike &
  operator ^=(intLike const & n)
  {
    data ^= n.data;
    return *this;
  }

  const bool operator ==(intLike const & n) const
  {
    return (data == n.data);
  }

  const bool operator !=(intLike const & n) const
  {
    return (data != n.data);
  }

  const bool operator <(intLike const & n) const
  {
    return (data < n.data);
  }

  const bool operator >(intLike const & n) const
  {
    return (data > n.data);
  }

  const bool operator >=(intLike const & n) const
  {
    return (data >= n.data);
  }

  const bool operator <=(intLike const & n) const
  {
    return (data <= n.data);
  }
};

int main() {
  intLike<int> test1(2), test2(1);
  
  cout << (test1 + test2).data << endl; // +
  cout << (test1 - test2).data << endl; // -
  cout << ++test1.data << endl; // ++(前)
  cout << ++++++++test1.data << endl; // ++は参照を返すからこんなこともできる
  cout << (test1++).data << endl; // ++(後) 変更はなし
  cout << --test1.data << endl; // --(前)
  cout << (test1--).data << endl; // --(後)
  test1 *= test2;
  cout << test1.data << endl; // *=
  test1 /= test2;
  cout << test1.data << endl; // /=
  test1 %= test2;
  cout << test1.data << endl; // %=
  test1 += test2;
  cout << test1.data << endl; // +=
  test1 -= test2;
  cout << test1.data << endl; // -=
  
  intLike<int> test3(32);
  test3 <<= test2;
  cout << test3.data << endl; // <<=
  test3 >>= test2;
  cout << test3.data << endl; // >>=
  test3 <<= test2;
  cout << test3.data << endl; // <<=
  
  test1 &= test2;
  cout << test1.data << endl; // &=
  test1 |= test2;
  cout << test1.data << endl; // |=
  test3 ^= test2;
  cout << test3.data << endl; // ^=

  intLike<int> test4(5), test5(5);
  cout << (test4 == test5) << endl; // true
  cout << (test4 != test5) << endl; // false
  cout << (test4 < test5) << endl; // false
  cout << (test4 > test5) << endl; // false
  cout << (test4 >= test5) << endl; // true
  cout << (test4 <= test5) << endl; // true

  return 0;
}