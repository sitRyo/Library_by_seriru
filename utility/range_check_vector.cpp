/*
 * std::vector<T>::operator [] による配列要素へのランダムアクセスを
 * std::vector<T>::at(size_type __n) に強制しているつもり
 * 
 * vectorをoverrideするのが手っ取り早いかと思ったが、virtual要素がないので普通に断念
 * C++初学者なのでめちゃくちゃな実装だがとりあえず
 * 
 * todo sortの引数に比較関数を持たせる
 */ 

#include <vector>
#include <functional>

template <class T>
class vector_at {
  using size_type = std::size_t;
  using _Tp = T;
  using reference = _Tp &;
  using _array = std::vector<_Tp>;

  size_type n;
  _array con;
  
public:
  vector_at(size_type n) : n(n) {
    con = _array(n);
  }

  reference
  operator[] (size_type __n) {
    return this->at(__n);
  }

  reference
  at (size_type __n) {
    return con.at(__n);
  }

  void
  push_back (_Tp t) {
    con.push_back(t);
  }

  void
  pop_back () {
    con.pop_back();
  }

  void
  sort_i () {
    std::sort(con.begin(), con.end());
  }

  void
  sort_d () {
    std::sort(con.begin(), con.end(), std::greater<_Tp>());
  }

  void
  resize (size_type __n) {
    con.resize(__n);
  }
};
