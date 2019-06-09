#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265f
#define RadToDeg 57.29577951f
#define DegToRad 0.017453293f

constexpr
double calcMod(double deg) {
  if (deg > 360) deg -= 360;
  return deg;
}

constexpr
double calcSin(double deg) {
  return sin(deg * DegToRad);
}

constexpr 
double calcCos(double deg) {
  return cos(deg * DegToRad);
}

constexpr
double calcTan(double deg) {
  return tan(deg * DegToRad);
}

int main() {
  cout << calcSin(calcMod(450)) << endl;
  cout << calcCos(19) << endl;
  cout << calcTan(90) << endl;
}