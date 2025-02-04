// 비슷한 단어
// https://www.acmicpc.net/problem/2607

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<string> words;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    words.push_back(s);
  }

  vector<int> ref_cnt(256, 0);
  for (int i = 0; i < words[0].size(); ++i) {
    ref_cnt[words[0][i]]++;
  }

  int len_x = words[0].length();

  int ans = 0;
  for (int i = 1; i < n; ++i) {
    vector<int> cnt(256, 0);
    for (int j = 0; j < words[i].size(); ++j) {
      cnt[words[i][j]]++;
    }

    int diff_sum = 0;
    int diff_pos = 0;
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
      int diff = abs(ref_cnt[ch] - cnt[ch]);
      diff_sum += diff;
      if (diff != 0) diff_pos++; 
    }

    int len_diff = len_x - words[i].length();
    if (abs(len_diff) >= 2) continue; 

    if (diff_sum <= 1) ans++;
    else if (diff_sum == 2 && diff_pos == 2) {
      ans++;
    }

    // AAA
    // ABA, in this case, diff is 2, but counted as answer
    // ACA
    // ABA, in this case, diff is 2, but counted as answer
    // count가 다른곳이 2개뿐이고 diff가 2이면 정답
  }

  cout << ans << "\n";

  return 0;
}