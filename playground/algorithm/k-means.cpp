/*
 * k-means法。全てconstexprにしたかったけどうまくできなかった。
 * random_deviceの定数式化はうまくいっているのだろうか...
 * assembly読まなきゃ
 */

#include <iostream>
#include <cstdio>
#include <utility>
#include <array>
#include <cmath>

using std::cout;
using std::endl;

template <uint32_t N>
class XorShift32 {
  using array_type = std::array<std::pair<uint32_t, uint32_t>, N>;
  uint32_t x_;
public:
  constexpr XorShift32(uint32_t x) 
    : x_(x) {}

  constexpr void genPair(array_type &C, int limit) const {
    uint32_t y = x_;
    for (int i = 0; i < N; ++i) {
      std::pair<uint32_t, uint32_t> p = std::make_pair(gen(y) % limit, gen(y) % limit);
      C.at(i) = p;
    }
  }

  constexpr uint32_t gen(uint32_t & y) const {
    y = y ^ (y << 13);
    y = y ^ (y >> 17);
    return y;
  }
};

/*
 * params: SEED, N = size, K = cluster_means
 */
template <uint32_t SEED, uint32_t N, uint32_t K>
class Cluster {
  using _Tp = uint32_t;
  using pi = std::pair<_Tp, _Tp>;

  using size_type = std::size_t;

  constexpr static size_type XMAX = 100;
  constexpr static size_type YMAX = 100;
  constexpr static _Tp seed_ = SEED;
public:
  std::array<pi, N> arr; // random point
  std::array<pi, K> cluster_means; // means

  std::array<double, N> cluster_distance[K]; // calulate distacne
  std::array<int, N> evalutes; // evalute means

  constexpr Cluster(std::array<pi, K> c) 
    : cluster_means(std::move(c))
  {
    constexpr XorShift32<N> xs(seed_);
    xs.genPair(arr, XMAX);
  }

  ~Cluster() {}

  constexpr void calculate_k_means() {
    size_type s = 0;
    while (s < 20) {
      for (int i = 0; i < K; ++i) calculate_distance(i);
      evaluete_cluster_distance();
      if (change_means()) break;
      s += 1;
    }
  }

  constexpr void calculate_distance(int k) {
    for (int i = 0; i < N; ++i) {
      cluster_distance[k][i] = distance(arr[i], cluster_means[k]);
    }
  }

  constexpr void evaluete_cluster_distance() {
    for (int i = 0; i < N; ++i) {
      double tmp = 100000;
      
      for (int kinda = 0; kinda < K; ++kinda) {
        if (kinda == 0) {
          evalutes[i] = kinda;
          tmp = cluster_distance[kinda][i];
        } else {
          if (tmp > cluster_distance[kinda][i]) {
            evalutes[i] = kinda;
            tmp = cluster_distance[kinda][i];
          }
        }
      }
    }
  }

  constexpr bool change_means() {
    bool flag = true;
    for (int kinda = 0; kinda < K; ++kinda) {
      // evalutes
      pi new_means = std::make_pair(0,0);
      size_type s = 0;
      for (int i = 0; i < N; ++i) {
        if (evalutes[i] == kinda) {
          new_means.first += arr[i].first;
          new_means.second += arr[i].second;
          s += 1;
        }
      }

      // to avoid divide zero
      new_means.first /= (s ? s : 1);
      new_means.second /= (s ? s : 1);
      if (new_means.first != cluster_means[kinda].first 
        or new_means.second != cluster_means[kinda].second) flag = false;
    }
    return flag;
  }

  // params
  // pair<_Tp, _Tp> t1, pair<_Tp, _Tp> t2
  constexpr double distance(pi t1, pi t2) {
    _Tp t1x = t1.first, t1y = t1.second;
    _Tp t2x = t2.first, t2y = t2.second;
    return std::sqrt((t2x - t1x) * (t2x - t1x) + (t2y - t1y) * (t2y - t1y));
  }

  constexpr void show() const {
    for (int i = 0; i < N; ++i) {
      printf("%d: %d %d\n", evalutes[i], arr[i].first, arr[i].second);
    }
  }
  
};


int main() {
  constexpr int k = 3;
  constexpr std::array<std::pair<uint32_t, uint32_t>, k> arr = 
  {
    std::make_pair(1, 3),
    std::make_pair(39, 11),
    std::make_pair(78, 90)
  };
  
  Cluster<1578423485, 20, k> cluster(arr);
  cluster.calculate_k_means();
  cluster.show();
}