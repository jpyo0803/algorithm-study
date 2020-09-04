//
// What does the fox say
// Link: https://www.acmicpc.net/problem/9536
//

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int T;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  cin.clear();
  string fb;
  getline(cin, fb);

  for (int t = 0; t < T; t++) {
    string str_sounds;
    getline(cin, str_sounds);
    
    vector<string> sounds;

    string buf;
    for (int i = 0; i < str_sounds.length(); i++) {
      if (str_sounds[i] == ' ') {
        sounds.push_back(buf);
        buf.clear();
      } else if (isalpha(str_sounds[i])) {
        buf += str_sounds[i];
      } 
    }
    sounds.push_back(buf);

    unordered_set<string> other_sounds;
    while (true) {
      string temp;
      getline(cin, temp);
      bool done = false;
      for (int i = 0 ; i < temp.length(); i++) {
        if (temp[i] == 's' && temp[i + 1] == 'a' && temp[i + 2] == 'y') {
          done = true;
          break;
        }
      }
      if (done) break;

      string buf;
      for (int i = temp.length() - 1; i >= 0; i--) {
        if (temp[i] == ' ') {
          reverse(buf.begin(), buf.end());
          other_sounds.insert(buf);
          buf.clear();
          break;
        } else if (isalpha(temp[i])) {
          buf += temp[i];
        }
      }
    }

    for (int i = 0; i < sounds.size(); i++) {
      if (other_sounds.find(sounds[i]) != other_sounds.end()) continue;
      cout << sounds[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
