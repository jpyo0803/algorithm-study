// 검문
// https://www.acmicpc.net/problem/2981

#include <bits/stdc++.h>

using namespace std;

bool chk[32000];
vector<int> pns, ans;
map<int, int> factor_cnt;
vector<int> used_factors;

int Gcd(int x, int y) {
  if (y == 0) return x;
  return Gcd(y, x % y);
}

int Pow(int b, int e) {
  if (e == 0) return 1;
  int x = Pow(b, e / 2);
  x *= x;
  if (e % 2 == 1) {
    x *= b;
  }
  return x;
}

void GenerateAns(int d, vector<int>& comb) {
  if (d == used_factors.size()) {
    int cand = 1;
    for (int i = 0; i < used_factors.size(); ++i) {
      cand *= Pow(used_factors[i], comb[i]);
    }
    if (cand > 1) {
      ans.push_back(cand);
    }
    return;
  }

  for (int i = 0; i <= factor_cnt[used_factors[d]]; ++i) {
    comb[d] = i;
    GenerateAns(d + 1, comb);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 2; i < 32000; ++i) {
    if (chk[i] == true) continue;
    pns.push_back(i);
    for (int j = i; j < 32000; j += i) {
      chk[j] = true;
    }
  }

  int N;
  cin >> N;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());
  vector<int> diff;
  for (int i = 1; i < N; ++i) {  // O(10000)
    for (int j = 0; j < i; ++j) {
      diff.push_back(arr[i] - arr[j]);  // always positive
    }
  }

  int gcd = diff[0];
  for (auto e : diff) {
    gcd = Gcd(gcd, e);
  }

  int i = 0;
  while (gcd != 1) {
    if (gcd % pns[i] == 0) {
      factor_cnt[pns[i]]++;
      gcd /= pns[i];
    } else {
      i++;
    }
  }

  for (auto& [x, y] : factor_cnt) {
    used_factors.push_back(x);
  }

  vector<int> comb(factor_cnt.size());
  GenerateAns(0, comb);

  sort(ans.begin(), ans.end());

  for (auto e : ans) {
    cout << e << " ";
  }

  return 0;
}