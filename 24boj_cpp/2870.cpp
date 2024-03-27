// 수학숙제
// https://www.acmicpc.net/problem/2870

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<string> nums;

  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    str += 'z';

    queue<char> q;
    for (auto ch : str) {
      if (ch >= '0' && ch <= '9') {
        q.push(ch);
      } else {
        while (q.size() > 1 && q.front() == '0') {
          q.pop();
        }

        string str;
        while (q.size()) {
          str += q.front();
          q.pop();
        }
        if (str.empty() == false) {
          nums.push_back(str);
        }
      }
    }
  }

  sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
    if (a.length() == b.length()) {
      for (int i = 0; i < a.length(); ++i) {
        if (a[i] == b[i]) continue;
        return a[i] < b[i];
      }
    }
    return a.length() < b.length();
  });

  for (auto& num : nums) {
    cout << num << "\n";
  }

  return 0;
}