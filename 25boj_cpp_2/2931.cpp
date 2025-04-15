// 가스관
// https://www.acmicpc.net/problem/2931

/*
  '|' = north - south
  '-' = west - east
  '+' = north - south, west - east, 
  '1' = east - south
  '2' = north - east
  '3' = north - west
  '4' = west - south
*/

#include <bits/stdc++.h>

using namespace std;

int r, c;
char arr[30][30];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int visited[30][30];

char pipe_types[7] = {'|', '-', '+', '1', '2', '3', '4'};
int mx, my, zx, zy;
int pipe_cnt = 0;

void ResetVisited() {
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      visited[i][j] = 0;
    }
  }
}

bool OutOfBound(int x, int y) {
  return x < 0 || x >= r || y < 0 || y >= c; // ok
}

bool CanGoEast(int x, int y) {
  return (arr[x][y] == '-' || arr[x][y] == '+' || arr[x][y] == '3' || arr[x][y] == '4');
}
bool CanGoWest(int x, int y) {
  return (arr[x][y] == '-' || arr[x][y] == '+' || arr[x][y] == '1' || arr[x][y] == '2');
}
bool CanGoSouth(int x, int y) {
  return (arr[x][y] == '|' || arr[x][y] == '+' || arr[x][y] == '2' || arr[x][y] == '3');
}
bool CanGoNorth(int x, int y) {
  return (arr[x][y] == '|' || arr[x][y] == '+' || arr[x][y] == '1' || arr[x][y] == '4');
}

int Solve(int x, int y, int dir) {
  if (OutOfBound(x, y)) return 0; // cannot go further, but count current pipe

  char tile = arr[x][y];
  if (tile == 'Z' || tile == '.') return 0;
  const int max_num_visit = (tile == '+' ? 2 : 1);
  if (visited[x][y] == max_num_visit) return 0; 
  visited[x][y]++;

  int next_dir;
  if (tile == '1') {
    if (dir == 1) next_dir = 2; // W to S
    else if (dir == 3) next_dir = 0; // N to E
  } else if (tile == '2') {
    if (dir == 2) next_dir = 0; // S to E
    else if (dir == 1) next_dir = 3; // W to N
  } else if (tile == '3') {
    if (dir == 0) next_dir = 3; // E to N
    else if (dir == 2) next_dir = 1; // S to W
  } else if (tile == '4') {
    if (dir == 0) next_dir = 2; // E to S
    else if (dir == 3) next_dir = 1; // N to W
  } else {
    next_dir = dir; // as it is
  }

  int nx = x + dx[next_dir];
  int ny = y + dy[next_dir];

  int curr_weight = (tile == '+' && visited[x][y] == 2) ? 0 : 1;

  if (next_dir == 0 && CanGoEast(nx, ny)) {
    return Solve(nx, ny, next_dir) + curr_weight;
  } else if (next_dir == 1 && CanGoWest(nx, ny)) {
    return Solve(nx, ny, next_dir) + curr_weight;
  } else if (next_dir == 2 && CanGoSouth(nx, ny)) {
    return Solve(nx, ny, next_dir) + curr_weight;
  } else if (next_dir == 3 && CanGoNorth(nx, ny)) {
    return Solve(nx, ny, next_dir) + curr_weight;
  }
  
  return curr_weight;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> r >> c;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> arr[i][j];
      if (arr[i][j] == 'M') {
        mx = i, my = j;
      } else if (arr[i][j] == 'Z') {
        zx = i, zy = j;
      }

      for (int k = 0; k < 7; ++k) {
        if (arr[i][j] == pipe_types[k]) {
          pipe_cnt++;
          break;
        }
      }
    }
  }

  int ans_x = -1, ans_y;
  char ans_type;

  bool done = false;
  for (int i = 0; i < r && !done; ++i) {
    for (int j = 0; j < c && !done; ++j) {
      if (arr[i][j] == '.') {
        for (int k = 0; k < 7 && !done; ++k) {
          arr[i][j] = pipe_types[k];
          
          // go from M to Z and check if the number of encountered pipes is pipe_cnt + 1

          int sx = -1, sy, dir;
          for (int l = 0; l < 4 && sx == -1; ++l) {
            int nx = mx + dx[l];
            int ny = my + dy[l];
            if (OutOfBound(nx, ny)) continue;
            if (l == 0 && CanGoEast(nx, ny)) { // East, valid = '-', '+', '3', '4'
              sx = nx, sy = ny, dir = l;
            } else if (l == 1 && CanGoWest(nx, ny)) { // West, valid = '-', '+', '1', '2'
              sx = nx, sy = ny, dir = l;
            } else if (l == 2 && CanGoSouth(nx, ny)) { // South, valid = '|', '+', '2', '3'
              sx = nx, sy = ny, dir = l;
            } else if (l == 3 && CanGoNorth(nx, ny)) { // North, valid = '|', '+', '1', '4'
              sx = nx, sy = ny, dir = l;
            }
          }

          if (sx != -1) {
            ResetVisited();

            int encountered_pipes = Solve(sx, sy, dir);
            // cout << i << " / " << j << " / " << arr[i][j] <<  " / " << dir << " : " << encountered_pipes << " .vs " << pipe_cnt  << endl;
            if (encountered_pipes == pipe_cnt + 1) {
              ans_x = i, ans_y = j;
              ans_type = pipe_types[k];
              done = true;
            }
          } 
          arr[i][j] = '.';
        }
      }
    }
  }

  cout << ans_x + 1 << " " << ans_y + 1 << " " << ans_type << "\n";
    
  return 0;
}