// 二元一次方程式を解く
#include <iostream>
#include <utility>

struct point2D {
  float x;
  float y;
};

using slope = float;
static constexpr int inf = -10000000;

// todo use tuple.
point2D lineIntersect(point2D p1, point2D p2, slope s1, slope s2) noexcept
{
  point2D ret;

  // two line is horizontal or overlap
  // exclude zero div error
  if (s1 == s2) {
    float y_intercept1 = -p1.y + s1 * p1.x;
    float y_intercept2 = -p2.y + s1 * p2.x;
    
    if (y_intercept1 == y_intercept2) {
      // 2 lines overlap so that solve is infinity
      ret.x = inf;
      ret.y = inf;
    } else {
      // 2 lines is horizontal so that solve is nothing
      ret.x = -inf;
      ret.y = -inf;
    }
  } else {
    float div_mother = s1 - s2;
    //static_assert(div_mother != 0.0, "s1 is equals to s2\n");
    float x = (s1 * p1.x - s2 * p2.x - p1.y + p2.y) / (s1 - s2);
    float y = s1 * (x - p1.x) + p1.y;

    ret.x = x;
    ret.y = y;
  }
  
  return ret;
}

int main() 
{
  point2D p1, p2;
  slope m1, m2;
  std::cin >> p1.x >> p1.y >> p2.x >> p2.y >> m1 >> m2;

  point2D intersect = lineIntersect(p1, p2, m1, m2);
  // test 1 11 1 -2 3 2.5 -> -25, -67
  std::cout << intersect.x << " " << intersect.y << std::endl;
}