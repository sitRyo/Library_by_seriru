#include <bits/stdc++.h>
using namespace std;

/**
 * 1 2 3 4 5 6      
 * 2 3 4 5 6 7
 * 3 4 5 6 7 8
 * 4 5 6 7 8 9
 * 5 6 7 8 9 10
 */

/**
 * 1 3 6 10 15 21      
 * 3 6 
 * 6 
 * 10 
 * 15 
 */

/**
 * @return bubunn
 */
int get(vector<vector<int>> const& a, int x1, int y1, int x2, int y2) {
  if (x1 > x2) {
    cerr << "x1 > x2\n";
    return 0;
  }
  if (y1 > y2) {
    cerr << "y1 > y2\n";
    return 0;
  }

  return a[y2][x2] - a[y2][x1-1] - a[y1-1][x2] + a[y1-1][x1-1];
}

/**
 * @return ruisekiwa
 */
vector<vector<int>> ruisekiwa(vector<vector<int>> const& a, int w, int h) {
  // w = 6, h = 5
  vector<vector<int>> sum(h+1, vector<int>(w+1, 0));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + a[i][j];
    }
  }

  for (int i = 0; i <= h; ++i) {
    for (int j = 0; j <= w; ++j) {
      cout << sum[i][j] << " ";
    }
    cout << endl;
  }

  return sum;
}

int main() {
  vector<vector<int>> mp 
  {{1,2,3,4,5,6},
  {2,3,4,5,6,7},
  {3,4,5,6,7,8},
  {4,5,6,7,8,9},
  {5,6,7,8,9,10}};

  auto sum = ruisekiwa(mp, 6, 5);
  cout << get(sum, 2, 2, 3, 3) << endl;
}