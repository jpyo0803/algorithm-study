// Family Tree (Bronze)
// https://www.acmicpc.net/problem/15765

#include <bits/stdc++.h>

using namespace std;

int n;
string a, b;

map<string, string> p;

void PrintAnswer(const string& a, const string& rel, const string& b) {
  cout << a << " is the " << rel << " of " << b << "\n";
}

string AppendGreatN(int x) {
  string ret;
  while (x--) ret += "great-";
  return ret;
}

string GetParent(const string& x) {
  auto it = p.find(x);
  if (it != p.end()) return it->second;
  return string();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin >> a >> b;
  for (int i = 0; i < n; ++i) {
    string m, c;
    cin >> m >> c;
    p[c] = m;
  }

  auto curr = a;
  vector<string> aa, bb;
  do {
    aa.push_back(curr);
    curr = GetParent(curr);
  } while (curr.size());

  curr = b;
  do {
    bb.push_back(curr);
    curr = GetParent(curr);
  } while (curr.size());

  string common;
  int da = -1, db;
  for (int i = 0; i < aa.size(); ++i) {
    for (int j = 0; j < bb.size(); ++j) {
      if (aa[i] == bb[j]) {
        common = aa[i];
        da = i;
        db = j;
        break;
      }
    }
    if (da != -1) break;
  }

  if (common.empty()) {
    cout << "NOT RELATED\n";
    return 0;
  } else if (da == 0 || db == 0) {
    if (db < da) {
      swap(da, db);
      swap(a, b);
    }

    string rel;
    if (db >= 3) rel += AppendGreatN(db - 2);
    if (db >= 2) rel += "grand-";
    rel += "mother";
    PrintAnswer(a, rel, b);
  } else if (da == 1 && db == 1) {
    cout << "SIBLINGS\n";
  } else if (da <= 1 || db <= 1) { // da > 0 && db > 0
    if (db < da) {
      swap(da, db);
      swap(a, b);
    }

    string rel;
    if (db >= 3) rel += AppendGreatN(db - 2);
    rel += "aunt";
    PrintAnswer(a, rel, b);
  } else {
    cout << "COUSINS\n";
  }

  return 0;
}