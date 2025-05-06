// 가장 가까운 두 점
// https://www.acmicpc.net/problem/2261

#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x, y, id;
};

Point strip[100005];

int DistSqr(const Point& a, const Point& b) {
  int dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

int Sqr(int x) { return x * x; }

int Solve(const vector<Point>& x_arr, const vector<Point>& y_arr) {
  if (x_arr.size() == 1) return 1e9;

  int n = x_arr.size();
  int mid = n / 2;
  Point mid_pt = x_arr[mid];

  vector<Point> left_x_arr(x_arr.begin(), x_arr.begin() + mid); // [0, mid)
  vector<Point> right_x_arr(x_arr.begin() + mid, x_arr.end()); // [mid, n)
  
  vector<Point> left_y_arr, right_y_arr;
  for (int i = 0; i < y_arr.size(); ++i) {
    if (y_arr[i].x < mid_pt.x) left_y_arr.push_back(y_arr[i]);
    else if (y_arr[i].x > mid_pt.x) right_y_arr.push_back(y_arr[i]);
    else {
      if (y_arr[i].id < mid_pt.id) left_y_arr.push_back(y_arr[i]);
      else right_y_arr.push_back(y_arr[i]);
    }
  }
  
  int min_left = Solve(left_x_arr, left_y_arr);
  int min_right = Solve(right_x_arr, right_y_arr);
  int min_dist = min(min_left, min_right);
  
  int strip_len = 0;
  int mid_x = (x_arr[mid - 1].x + x_arr[mid].x) / 2;
  for (const auto& e : y_arr) {
    if (Sqr(mid_x - e.x) < min_dist) { // if equal, it is only a tie when y's are equal, it still does not help
      strip[strip_len] = e;
      strip_len++;
    }
  }
  
  for (int i = 0; i < strip_len - 1; ++i) { // O(N)
    for (int j = i + 1; j < strip_len && (Sqr(strip[j].y - strip[i].y) < min_dist); ++j) { // max 7 times, O(1)
      min_dist = min(min_dist, DistSqr(strip[i], strip[j]));
    }
  }
  return min_dist;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<Point> x_pts(n), y_pts;

  for (int i = 0; i < n; ++i) cin >> x_pts[i].x >> x_pts[i].y;
  sort(x_pts.begin(), x_pts.end(), [](const Point& a, const Point& b) { return a.x < b.x; } );
  
  for (int i = 0; i < n; ++i) x_pts[i].id = i;
  y_pts = x_pts;

  sort(y_pts.begin(), y_pts.end(), [](const Point& a, const Point& b) { return a.y < b.y; } );

  cout << Solve(x_pts, y_pts) << "\n";

  return 0;
}