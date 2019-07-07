#include <vector>
#include <iostream>
namespace slc {

/**
 * @brief paramの要素だけネストしたvector型を返すメタ関数. 
 * @param THead head 最後の引数
 * @retval sizeof...(param)のvector
 */
template <class Thead>
constexpr auto make_vector(Thead head)
{
  return std::vector<Thead>(head);
}

/**
 * @brief paramの要素だけネストしたvector型を返すメタ関数. 要素数はゼロ
 * @param head i次元の要素
 * @param tail 引数
 * @retval sizeof...(param)のvector
 */
template <class THead, class ...Args>
constexpr auto make_vector(THead head, Args... tail) 
{
  return std::vector<decltype(make_vector(tail...))>();
}
};

// vector<int> 
using std::cout;
using std::endl;

int main(){
  auto vec = slc::make_vector(1, 10, 'a'); // vector<vector<int>>
  int n = 3;
  
  cout << endl;
}