// A+B
// https://www.acmicpc.net/problem/9267

/*
  x, y > 0 인 후보를 구한 후 gcd(x, y) = 1 인지 확인
  이때 [tx, ty] 범위를 모두 확인하는데 이론적인 시간복잡도에서는 안되야 정상인
  것 같다. 하지만 AC받음
*/

#include <bits/stdc++.h>

#define ll128 __int128

using namespace std;

long long a, b, s;

void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

pair<ll128, pair<ll128, ll128>> EEA(ll128 a, ll128 b, pair<ll128, ll128> x,
                                    pair<ll128, ll128> y) {
  if (b == 0) return {a, x};
  ll128 q = a / b;      // q <= a
  ll128 r = a - q * b;  // r <= a

  pair<ll128, ll128> next_y(x.first - q * y.first, x.second - q * y.second);
  return EEA(b, r, y, next_y);
}

pair<ll128, pair<ll128, ll128>> EEA(long long a, long long b) {
  return EEA(a, b, {1, 0}, {0, 1});
}

ll128 Ceil(ll128 n, ll128 d) {
  if ((n > 0 && d > 0)) {
    return (n + d - 1) / d;
  } else if (n < 0 && d < 0) {
    return (-n + (-d - 1)) / -d;
  }
  // different sign
  return n / d;
}

ll128 Floor(ll128 n, ll128 d) {
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

  cin >> a >> b >> s;
  if (a == 0 && b == 0 && s == 0) {
    YES();
  } else if (a == 0 && b == 0 && s != 0) {
    NO();
  } else if (a == 0 && b != 0 && s == 0) {
    YES();
  } else if (a == 0 && b != 0 && s != 0) {
    if (s % b == 0) {
      YES();
    } else {
      NO();
    }
  } else if (a != 0 && b == 0 && s == 0) {
    YES();
  } else if (a != 0 && b == 0 && s != 0) {
    if (s % a == 0) {
      YES();
    } else {
      NO();
    }
  } else if (a != 0 && b != 0 && s == 0) {
    NO();
  } else {
    // a, b, s >= 1
    if (a == s || b == s) {
      YES();
    } else {
      auto result = EEA(a, b);
      ll128 g = result.first;
      ll128 x0 = result.second.first;
      ll128 y0 = result.second.second;

      if (s % g == 0) {
        ll128 xi = x0 * s / g;
        ll128 yi = y0 * s / g;
        ll128 tx = Ceil((-xi + 1) * g, b);
        ll128 ty = Floor((-yi + 1) * -g, a);

        // cout << (long long)xi << " / " << (long long)yi << endl;
        // cout << (long long)tx << " / " << (long long)ty << endl;

        if (tx <= ty) {
          // here x, y >= 1

          bool ok = false;
          for (ll128 t = tx; t <= ty; ++t) {
            ll128 xx = xi + b * t / g;  // x가 최소로 기준
            ll128 yy = yi - a * t / g;
            if (gcd(xx, yy) == 1) {
              ok = true;
              break;
            }
          }

          if (ok) {
            YES();
          } else {
            NO();
          }
        } else {
          NO();
        }
      } else {
        NO();
      }
    }
  }

  return 0;
}