//
// String search example.
//

#include <iostream>
#include <vector>
#include "string_search.hpp"

using namespace std;

int main() {
  string hay = "abcdabcabcabcdabcd";
  string key = "abcd";

  vector<int> ret = SearchKMP(hay, key);

  cout << "Number Found : " << ret.size() << endl;
  for (auto& idx : ret) {
    cout << idx << " ";
  }
  cout << endl;

  return 0;
}
