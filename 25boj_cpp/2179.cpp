// 비슷한 단어
// https://www.acmicpc.net/problem/2179

#include <bits/stdc++.h>

using namespace std;

int n;

int CountPrefix(const string& a, const string& b) {
  int len = min(a.length(), b.length());
  int mc = 0;
  for (int i = 0; i < len; ++i) {
    if (a[i] == b[i]) mc++;
    else break;
  }
  return mc;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<string> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i];

  auto vvs = vv;
  sort(vvs.begin(), vvs.end());

  vector<string> max_prefixes;
  int max_prefix_len = 0;
  
  for (int i = 0; i < n - 1; ++i) {
    int pfc = CountPrefix(vvs[i], vvs[i + 1]);
    if (pfc == max_prefix_len) {
      max_prefixes.push_back(vvs[i].substr(0, pfc));
    } else if (pfc > max_prefix_len) {
      max_prefix_len = pfc;
      max_prefixes.clear();
      max_prefixes.push_back(vvs[i].substr(0, max_prefix_len));
    }
  }

  string targ_pf;
  bool done = false;
  for (const auto& e : vv) {
    for (const auto& e2 : max_prefixes) {
      if (e.substr(0, max_prefix_len) == e2) {
        targ_pf = e2;
        done = true;
        break;
      }
    }
    if (done) break;
  }

  string ans1, ans2;
  for (const auto& e : vv) {
    if (targ_pf == e.substr(0, max_prefix_len)) {
      if (ans1.empty()) {
        ans1 = e;
      } else if (ans1 != e) {
        ans2 = e;
        break;
      }
    }
  }

  cout << ans1 << "\n" << ans2 << "\n";

  return 0;
}