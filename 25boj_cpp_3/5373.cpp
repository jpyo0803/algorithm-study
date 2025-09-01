// 큐빙 
// https://www.acmicpc.net/problem/5373

#include <bits/stdc++.h>

using namespace std;

int t;

struct Cube {
  char f[6][3][3];

  Cube() {
    // 0 - top, while
    // 1 - bot, yello
    // 2 - front, red
    // 3 - back, oran
    // 4 - left, gree
    // 5 - right, blu
    char colors[6] = {'w','y','r','o','g','b'};
    for (int k = 0; k < 6; ++k) {
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          f[k][i][j] = colors[k];
        }
      }
    }
  }

  void Rotate(int s, bool cw) {
    if (cw) CWFace(s);
    else CCWFace(s);

    if (s == 0) U(cw);
    else if (s == 1) D(cw);
    else if (s == 2) F(cw);
    else if (s == 3) B(cw);
    else if (s == 4) L(cw);
    else if (s == 5) R(cw);
  }
  
  void U(bool cw) {
    Side(cw, f[3][2][0],f[3][2][1],f[3][2][2]
          ,f[5][0][2],f[5][0][1],f[5][0][0]
          ,f[2][0][2],f[2][0][1],f[2][0][0]
          ,f[4][0][2],f[4][0][1],f[4][0][0]);
  }

  void D(bool cw) { // ok
    Side(cw, f[2][2][0],f[2][2][1],f[2][2][2]
          ,f[5][2][0],f[5][2][1],f[5][2][2]
          ,f[3][0][2],f[3][0][1],f[3][0][0]
          ,f[4][2][0],f[4][2][1],f[4][2][2]);
  }
    // 0 - top, while
    // 1 - bot, yello
    // 2 - front, red
    // 3 - back, oran
    // 4 - left, gree
    // 5 - right, blu
  void F(bool cw) { // ok
    Side(cw, f[0][2][0],f[0][2][1],f[0][2][2]
          ,f[5][0][0],f[5][1][0],f[5][2][0]
          ,f[1][0][2],f[1][0][1],f[1][0][0]
          ,f[4][2][2],f[4][1][2],f[4][0][2]);
  }

  void B(bool cw) { // ok
    Side(cw, f[1][2][0],f[1][2][1],f[1][2][2]
          ,f[5][2][2],f[5][1][2],f[5][0][2]
          ,f[0][0][2],f[0][0][1],f[0][0][0]
          ,f[4][0][0],f[4][1][0],f[4][2][0]);
  }

  void L(bool cw) { // ok
    Side(cw, f[0][0][0],f[0][1][0],f[0][2][0]
          ,f[2][0][0],f[2][1][0],f[2][2][0]
          ,f[1][0][0],f[1][1][0],f[1][2][0]
          ,f[3][0][0],f[3][1][0],f[3][2][0]);
  }

  void R(bool cw) { // ok
    Side(cw, f[0][2][2],f[0][1][2],f[0][0][2]
          ,f[3][2][2],f[3][1][2],f[3][0][2]
          ,f[1][2][2],f[1][1][2],f[1][0][2]
          ,f[2][2][2],f[2][1][2],f[2][0][2]);
  }

  void Side(bool cw, char& u1, char& u2, char& u3, 
              char& r1, char& r2, char& r3, 
              char& d1, char& d2, char& d3, 
              char& l1, char& l2, char& l3) {
                cw ? CWSide(u1, u2, u3, r1, r2, r3, d1, d2, d3, l1, l2, l3) 
                : CCWSide(u1, u2, u3, r1, r2, r3, d1, d2, d3, l1, l2, l3);
  }

  void CWSide(char& u1, char& u2, char& u3, 
              char& r1, char& r2, char& r3, 
              char& d1, char& d2, char& d3, 
              char& l1, char& l2, char& l3) {
    char tmp = l3;
    l3 = d3, d3 = r3, r3 = u3, u3 = tmp;
    tmp = l2;
    l2 = d2, d2 = r2, r2 = u2, u2 = tmp;
    tmp = l1;
    l1 = d1, d1 = r1, r1 = u1, u1 = tmp;
  }

  void CCWSide(char& u1, char& u2, char& u3, 
              char& r1, char& r2, char& r3, 
              char& d1, char& d2, char& d3, 
              char& l1, char& l2, char& l3) {
    char tmp = l3;
    l3 = u3, u3 = r3, r3 = d3, d3 = tmp;
    tmp = l2;
    l2 = u2, u2 = r2, r2 = d2, d2 = tmp;
    tmp = l1;
    l1 = u1, u1 = r1, r1 = d1, d1 = tmp;
  }

  void CWFace(int s) {
    char tmp[3][3];
    tmp[1][1] = f[s][1][1];
    tmp[0][0] = f[s][2][0];
    tmp[0][1] = f[s][1][0];
    tmp[0][2] = f[s][0][0];
    tmp[1][2] = f[s][0][1];
    tmp[2][2] = f[s][0][2];
    tmp[2][1] = f[s][1][2];
    tmp[2][0] = f[s][2][2];
    tmp[1][0] = f[s][2][1];
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        f[s][i][j] = tmp[i][j];
      }
    }
  }

  void CCWFace(int s) {
    char tmp[3][3];
    tmp[1][1] = f[s][1][1];
    tmp[0][0] = f[s][0][2];
    tmp[0][1] = f[s][1][2];
    tmp[0][2] = f[s][2][2];
    tmp[1][2] = f[s][2][1];
    tmp[2][2] = f[s][2][0];
    tmp[2][1] = f[s][1][0];
    tmp[2][0] = f[s][0][0];
    tmp[1][0] = f[s][0][1];
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        f[s][i][j] = tmp[i][j];
      }
    }
  }

  void PrintTop() const {
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        cout << f[0][i][j];
      }
      cout << "\n";
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    Cube cube;
    
    int k;
    cin >> k;
    
    while (k--) {
      string c;
      cin >> c;

      int s;
      if (c[0] == 'U') s = 0;
      else if (c[0] == 'D') s = 1;
      else if (c[0] == 'F') s = 2;
      else if (c[0] == 'B') s = 3;
      else if (c[0] == 'L') s = 4;
      else if (c[0] == 'R') s = 5;

      bool cw = c[1] == '+';
      cube.Rotate(s, cw);
    }

    cube.PrintTop();
  }

  return 0;
}