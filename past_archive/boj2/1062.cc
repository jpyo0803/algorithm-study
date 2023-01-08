//
// Lesson
// Problem: https://www.acmicpc.net/problem/1062
//

#include <iostream>
#include <vector>

using namespace std;
int N, K;
vector<string> words;
vector<char> alphas;
bool learned[26];
bool alpha_pool[26];

void comb(int nth, int start_idx, int& ans) {
  if (nth == K) {
    int local_ans{0};
    for (auto word : words) {
      bool pass{true};
      for (int j = 4; j < word.length() - 4; j++) {
        if (!learned[word[j] - 'a']) {
          pass = false;
          break;
        }
      }
      if (pass) local_ans += 1;
    }
    ans = max(ans, local_ans);
    return;
  }

  for (int i = start_idx; i < alphas.size(); i++) {
    learned[alphas[i] - 'a'] = true;
    comb(nth + 1, i + 1, ans);
    learned[alphas[i] - 'a'] = false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> K;
  K -= 5;

  if (K < 0) {
    cout << 0;
    return 0;
  }

  learned['a' - 'a'] = true;
  learned['n' - 'a'] = true;
  learned['t' - 'a'] = true;
  learned['i' - 'a'] = true;
  learned['c' - 'a'] = true;

  string word;
  for (int i = 0; i < N; i++) {
    cin >> word;
    words.push_back(word);
    for (int j = 4; j < word.length() - 4; j++) {
      if (!learned[word[j] - 'a']) {
        alpha_pool[word[j] - 'a'] = true;
      }
    }
  }

  for (int i = 0; i < 26; i++) {
    if (alpha_pool[i]) {
      alphas.push_back('a' + i);
    }
  }

  while (alphas.size() < K) {
    alphas.push_back(' ');
  }

  int ans{0};
  comb(0, 0, ans);
  cout << ans;
  return 0;
}