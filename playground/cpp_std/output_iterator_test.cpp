/*
 * output_iteratorのテスト iterator_categoryにoutput_iteratorにして, operator = を定義。 メンバにcontainerの左辺値参照を持ち、push_backする。
 */

#include <iostream>
#include <iterator>
#include <vector>

template <class Container>
struct plusTwoIterator {
  // boiler plate code
  using difference_type = void;
  using value_type = void;
  using reference = void;
  using pointer = void;

  using iterator_category = std::output_iterator_tag;

  plusTwoIterator & operator *() {return *this;}
  plusTwoIterator & operator ++() {return *this;}
  plusTwoIterator & operator ++(int) {return *this;}

  plusTwoIterator(Container & container) : c(container) {}

  plusTwoIterator & operator=(typename Container::value_type const & x) {
    c.push_back(x + 2);
    return *this;
  }

  Container & c;
};

int main() {
  using iv = std::vector<int>;
  std::vector<int> v = {2, 4, 6, 8, 10}, b;
  
  std::copy(begin(v), end(v), plusTwoIterator<iv>(b));
  std::copy(begin(b), end(b), std::ostream_iterator<int>(std::cout, " "));
}
