#include <iostream>
#include <vector>

class classB {
public:
  char b;
  char* p;

  classB(char b) : b(b), p(new char[10]) {}
  ~classB() {
    std::cout << "invoke destructorB " << b << std::endl;
  }
};

class classA {
public:
  std::vector<classB*> mClass;
  ~classA() {
    std::cout << "invoke destructorA\n";
    while (!mClass.empty())
      { delete mClass.back(); mClass.pop_back(); }
  }

  void setClassB(classB * ins) {
    mClass.push_back(ins);
    // std::cout << "invoke B" << std::endl;
  }

  void loadData() {
    classB* b = new classB('1');
    classB* c = new classB('2');
    setClassB(b); // bは入れる, cは何もしない
    printf("%p\n", b);
    // bは生存？ cは死ぬ?
  }

  void showData() {
    printf("%p\n", mClass.front());
  }
};

int main() {
  classA p;
  p.loadData();
  // vector<class*> p したら delete class.back(), pop_back()しなきゃいけない
}