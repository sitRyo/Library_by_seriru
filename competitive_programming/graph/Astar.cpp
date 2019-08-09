/* Astar 2019/8/8 created by seriru */

#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

using Vector2 = vector<vector<int>>;
using Point = pair<int,int>;

Vector2 generateField(int h, int w) {
  random_device rd;
  Vector2 field(h, vector<int>(w));

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      const unsigned int p = rd() % 10;
      if (p < 7) field[i][j] = 0;
      else field[i][j] = 1;
    }
  }

  for (auto row : field) {
    for (auto element : row) {
      cout << element << " ";
    }
    cout << "\n";
  }

  return field;
}

// map

struct ANode {
  Point pos;
  Point parent;
  int hScore;
  int rScore;

  int x() { return pos.second; }
  int y() { return pos.first; }
  int score() { return hScore + rScore; }

  bool operator==(ANode const& rhs) const { return (rhs.pos.first == pos.first & rhs.pos.second == pos.second); }
  bool operator==(Point const& rhs) const { return (rhs.first == pos.first & rhs.second == pos.second); }
  bool operator!=(ANode const& rhs) const { return (rhs.pos.first != pos.first | rhs.pos.second != pos.second); }
  bool operator!=(Point const& rhs) const { return (rhs.first != pos.first | rhs.second != pos.second); }
};

int calcHScore(Point temp, Point goal) {
  return (abs(temp.first - goal.first) + abs(temp.second - goal.second));
}

vector<Point> Astar(Vector2 const& field, Point start, Point goal, int h, int w) {
  random_device rd;
  map<Point, bool> openList;
  map<Point, bool> closeList;

  map<Point, ANode> ANodeHashList;

  ANode currentNode = {start, make_pair(-1, -1), 0, 0};
  openList[start] = true;

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, -1, 1};

  bool isReachToGoal = false;

  // 4方向のマスのヒューリスティックスコアを計算
  int cnt = 0;
  while (currentNode != goal) {
    cnt += 1;
    if (cnt > 50) exit(0);
    ANodeHashList[currentNode.pos] = currentNode;
    closeList[currentNode.pos] = true;
    Point par = currentNode.pos;
    vector<ANode> openNodeTmp;
    
    for (int i = 0; i < 4; ++i) {
      int nx = dx[i] + currentNode.x();
      int ny = dy[i] + currentNode.y();
      Point p = make_pair(ny, nx);
      
      if (nx < 0 || ny < 0 || nx >= w || ny >= h || field[ny][nx] == 1 || closeList[p]) {
      continue;
      }

      ANode candidateNode = {p, par, 0, currentNode.rScore + 1};
      // もし隣接したマスがゴールだったら
      if (p == goal) {
        
        currentNode = candidateNode;
        isReachToGoal = true;
        break;
      }

      // そうでなければヒューリスティックスコアを計算する
      candidateNode.hScore += calcHScore(candidateNode.pos, goal);
      // このループでオープンしたマスの配列にpush     
      openNodeTmp.push_back(candidateNode);
      openList[p] = true;
    }

    if (isReachToGoal) break;

    // 一番ヒューリスティックスコアの低いマスに移動
    ANode nextNode;
    int minScore = 10000;
    // 袋小路にいる。
    if (openNodeTmp.empty()) { 
      // 親をクローズリストから外す。
      closeList[currentNode.parent] = false;
      // currentNodeを一個前に戻す
      nextNode = ANodeHashList[currentNode.parent];
    } else {
      for (auto node : openNodeTmp) {
        if (minScore > node.score()) {
          nextNode = node;
          minScore = node.score();
        } else if (minScore == node.hScore) {
          // もし同じスコアのマスがあったら？
          int forceChange = rd() % 2;
          // 50％の確率で新しいマス目を採用する
          if (forceChange == 0) {
            nextNode = node;
          }
        }  
      }
    }
    
    nextNode.hScore = 0;
    currentNode = nextNode;
  }

  vector<Point> route;
  // 経路復元
  pair<int,int> root = make_pair(-1, -1);
  while (currentNode.parent != root) {
    route.push_back(currentNode.pos);
    currentNode = ANodeHashList[currentNode.parent];
  }

  reverse(route.begin(), route.end());
  return route;
}

Point getEmptyPointFirst(Vector2 field, int h, int w) {
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (field[i][j] == 0) {
        return make_pair(i, j);
      }
    }
  }

  return make_pair(-1, -1);
}

Point getEmptyPointEnd(Vector2 field, int h, int w) {
  for (int i = h-1; i >= 0; --i) {
    for (int j = w-1; j >= 0; --j) {
      if (field[i][j] == 0) {
        return make_pair(i, j);
      }
    }
  }

  return make_pair(-1, -1);
}

int main() {
  Vector2 field = generateField(10, 10);
  Point s = getEmptyPointFirst(field, 10, 10);
  Point g = getEmptyPointEnd(field, 10, 10);
  cout << "start " << s.first << " " << s.second << endl;
  cout << "goal " << g.first << " " << g.second << endl;
  vector<Point> route = Astar(field, s, g, 10, 10);
  for (auto itr : route) {
    cout << itr.first << " " << itr.second << endl;
  }
}