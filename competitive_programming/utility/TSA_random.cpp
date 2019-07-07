#include <bits/stdc++.h>
using namespace std;

// create Random Path
// 巡回セールスマン問題とか解くのに初期状態の遺伝子を作る

constexpr int countCities = 10;

template <int N>
constexpr
void shuffleChromosome(array<array<int, N>, N>& chromosome) {
  random_device rd;
  mt19937 mt(rd());
  for_each(chromosome.begin(), chromosome.end(), [&](auto& element) {
    shuffle(element.begin(), element.end(), mt);
    for (auto&& itr : element) {
      cout << itr << " ";
    }
    cout << endl;
  });
}

template <int N>
constexpr
void initChromosome(array<array<int, N>, N>& chromosome) {
  for_each(chromosome.begin(), chromosome.end(), [](auto& element) {
    iota(element.begin(), element.end(), 1);
  });
  shuffleChromosome<countCities>(chromosome);
}

int main() {
  array<array<int, countCities>, countCities> chromosome;  
  initChromosome<countCities>(chromosome);
}