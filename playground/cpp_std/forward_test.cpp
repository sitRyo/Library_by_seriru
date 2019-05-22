// forwardはテンプレート引数を転送する。
// 正しくは右辺値にキャストする。
// 仮引数は, T & になるため...
// (i) もし引数がT&&の場合は, T&& && でrvalueで転送
// (ii) もし引数がTの場合は, T&& & でlvalueで転送

#include <utility>
#include <cstdio>

class Test {
public:
  int a = 1;
  Test() = default;
  ~Test() = default;
  Test (Test const &right) { *this = right; }
  Test &operator=(Test const &right) {
    printf("called copy constructor\n");
  }
  Test (Test &&right) { *this = std::move(right); }
  Test &operator=(Test &&right) {
    printf("called move constructor\n");
  }
};

void g(Test t) {}

template <class T>
void f(T&& t) {
  g(t); // copy constructor (T&& tは左辺値だから)
  g(std::forward<T>(t)); // move constructor (T&& tを右辺値にキャストして転送)
}

int main(){
  Test t;
  f(std::move(t));
  f(t); // copyが呼ばれる
}