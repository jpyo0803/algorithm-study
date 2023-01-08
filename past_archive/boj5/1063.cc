//
// King
// Link: https://www.acmicpc.net/problem/1063
//

#include <iostream>

using namespace std;

struct Unit {
  int r, c;
  Unit(int rr, int cc) : r(rr), c(cc) {}

  bool IsMoveValid(int dr, int dc) const {
    int nr = r + dr;
    int nc = c + dc;
    return nr >= 0 && nr < 8 && nc >= 0 && nc < 8;
  }

  bool IsOntheWay(const Unit& other, int dr, int dc) const {
    return (r + dr == other.r) && (c + dc == other.c);
  }

  void Update(int dr, int dc) {
    r += dr;
    c += dc;
  }
};

void Move(const string& move, Unit& king, Unit& rock) {
  int dr, dc;
  if (move == "R") {
    dr = 1;
    dc = 0;
  } else if (move == "L") {
    dr = -1;
    dc = 0;
  } else if (move == "B") {
    dr = 0;
    dc = -1;
  } else if (move == "T") {
    dr = 0;
    dc = 1;
  } else if (move == "RT") {
    dr = dc = 1;
  } else if (move == "LT") {
    dr = -1;
    dc = 1;
  } else if (move == "RB") {
    dr = 1;
    dc = -1;
  } else if (move == "LB") {
    dr = dc = -1;
  }
  if (king.IsMoveValid(dr, dc)) {
    if (king.IsOntheWay(rock, dr, dc)) {
      if (rock.IsMoveValid(dr, dc)) {
        king.Update(dr, dc);
        rock.Update(dr, dc);
      }
    } else {
      king.Update(dr, dc);
    }
  }
}

int main() {
  string coord;

  cin >> coord;
  Unit king(coord[0] - 'A', coord[1] - '1');
  cin >> coord;
  Unit rock(coord[0] - 'A', coord[1] - '1');
  int num_move;
  cin >> num_move;

  for (int i = 0; i < num_move; i++) {
    string move;
    cin >> move;
    Move(move, king, rock);
  }
  cout << static_cast<char>(king.r + 'A') << king.c + 1 << endl;
  cout << static_cast<char>(rock.r + 'A') << rock.c + 1 << endl;
  return 0;
}
