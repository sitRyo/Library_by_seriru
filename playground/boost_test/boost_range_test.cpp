#include <iostream>
#include <vector>
#include <string>

#include <boost/range/algorithm.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/strided.hpp>
#include <boost/range/adaptor/transformed.hpp>

int main() {
  std::vector<int> v = {3, 4, 1, 2, 5};
  boost::sort(v);
  std::for_each(begin(v), end(v), [](auto&& itr){
    std::cout << itr << std::endl;
  });

  boost::copy(
    boost::irange(0, 100)
      | boost::adaptors::strided(2)
      | boost::adaptors::transformed([](int n){ return 2 * n; }),
    std::ostream_iterator<int>(std::cout, " "));
  
  std::cout << "\n";

  std::string str;
  boost::copy(
    boost::irange<char>('a', 'z' + 1)
      | boost::adaptors::transformed([](char c) { return c - ('a' - 'A'); }),
    std::back_inserter(str));
  std::cout << str << "\n";
}