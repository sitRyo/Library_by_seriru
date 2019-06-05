/** 
 * 円の中心と球の中心の構造体
 * 衝突検知
*/

#include <iostream>
#include <cmath>

struct circle {
  using R_type = double;
  double center[2];
  R_type radius;
};

struct sphere {
  using R_type = double;
  double center[3];
  R_type radius;
};

constexpr
bool colSphere(sphere lhs, sphere rhs) {
  return (
    pow(lhs.center[0], 2) + pow(lhs.center[1], 2) + pow(lhs.center[2], 2) < pow(lhs.radius, 2) + pow(rhs.radius, 2)
  );
}

constexpr
bool colCircle(circle lhs, circle rhs) {
  return (
    pow(lhs.center[0], 2) + pow(lhs.center[1], 2) < pow(lhs.radius, 2) + pow(rhs.radius, 2)
  );
}

int main() {
  
}
