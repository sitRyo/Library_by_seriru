#include <iostream>
#include <cmath>
#include <vector>
using std::cout;
using std::endl;
using std::cin;

struct Point {
  double x, y, z;
};

// distance between 2 points.
constexpr
double pythagorean_dim2(Point p1, Point p2) {
  return sqrt(abs(p1.x - p2.x) * abs(p1.x - p2.x) + abs(p1.y - p2.y) * abs(p1.y - p2.y));  
}

// distacne between 3 points
constexpr
double pythagorean_dim3(Point p1, Point p2) {
  return sqrt(abs(p1.x - p2.x) * abs(p1.x - p2.x) + abs(p1.y - p2.y) * abs(p1.y - p2.y) + abs(p1.z - p2.z) * abs(p1.z - p2.z));
}

// test
int main() {
  double a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;
  Point p1 = {a, b, c}, p2 = {d, e, f};
  cout << pythagorean_dim3(p1, p2) << endl;
}