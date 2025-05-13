// 해의 개수
// https://www.acmicpc.net/problem/11611

#include <bits/stdc++.h>

using namespace std;

long long A, B, C, X1, X2, Y1, Y2;

pair<long long, pair<long long, long long>> EEA(long long a, long long b, pair<long long, long long> x, pair<long long, long long> y) {
  if (b == 0) return {a, x};
  long long q = a / b; // q <= a
  long long r = a - q * b; // r <= a
  
  pair<long long, long long> next_y(x.first - q * y.first, x.second - q * y.second);
  return EEA(b, r, y, next_y);
}

pair<long long, pair<long long, long long>> EEA(long long a, long long b) {
  return EEA(a, b, {1, 0}, {0, 1});
}

long long Ceil(long long n, long long d) {
  if ((n > 0 && d > 0)) {
    return (n + d - 1) / d;
  } else if (n < 0 && d < 0) {
    return (-n + (-d - 1)) / -d;
  }
  // different sign
  return n / d;
}

long long Floor(long long n, long long d) {
  if ((n >= 0 && d > 0) || (n <= 0 && d < 0)) {
    return n / d;
  } 
  // different sign
  if (n < 0) {
    return -(-n + d - 1) / d;
  } else {
    return (n + (-d - 1)) / d;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> A >> B >> C >> X1 >> X2 >> Y1 >> Y2; // -1e8 <= a,b,c,...,y2 <= 1e8

  long long ans = 0;
  
  if (A == 0 && B == 0 && C == 0) {
    ans = (X2 - X1 + 1) * (Y2 - Y1 + 1);
  } else if (A == 0 && B == 0 && C != 0) {
    ans = 0;
  } else if (A == 0 && B != 0 && C == 0) {
    if (Y1 <= 0 && 0 <= Y2) ans = (X2 - X1 + 1);
    else ans = 0;
  } else if (A == 0 && B != 0 && C != 0) {
    if (C % B == 0)  {
      long long Y = C / B;
      if (Y1 <= Y && Y <= Y2) {
        ans = (X2 - X1 + 1);
      } else {
        ans = 0;
      }
    } else ans = 0;
  } else if (A != 0 && B == 0 && C == 0) {
    if (X1 <= 0 && 0 <= X2) ans = (Y2 - Y1 + 1);
    else ans = 0;
  } else if (A != 0 && B == 0 && C != 0) {
    if (C % A == 0) {
      long long X = C / A;
      if (X1 <= X && X <= X2) {
        ans = (Y2 - Y1 + 1);
      } else {
        ans = 0;
      }
    } else ans = 0;
  } else {
    auto result = EEA(A, B);

    long long g = result.first;
    if (C % g == 0) {
      long long x0 = result.second.first;
      long long y0 = result.second.second;
      long long xi = x0 * -C / g;
      long long yi = y0 * -C / g;
      // cout << "g : " << g << endl;
      // cout << xi << " / " << yi << endl;

      if (B * g < 0) swap(X1, X2);
      if (A * g < 0) swap(Y1, Y2);
      long long t_low_x = Ceil((X1 - xi) * g, B);
      long long t_high_x = Floor((X2 - xi) * g, B);
      // cout << (Y2 - yi) * g << endl;
      // cout << (Y1 - yi) * g << endl;
      long long t_low_y = Ceil((Y2 - yi) * g, -A);
      long long t_high_y = Floor((Y1 - yi) * g, -A);
      // cout << "A: " << A << ", g = " << g << endl;
      // cout << "t low : " << t_low_x << " / " << t_low_y << endl;
      // cout << "t high : " << t_high_x << " / " << t_high_y << endl;

      long long t_low = max(t_low_x, t_low_y);
      long long t_high = min(t_high_x, t_high_y);
      // cout << t_low << " / " << t_high << endl;
      ans = max(0LL, t_high - t_low + 1);
    } else {
      ans = 0;
    }
  }

  cout << ans << "\n";

  return 0;
}