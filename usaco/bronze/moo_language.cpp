// Moo Language (Bronze)
// https://www.acmicpc.net/problem/28035

#include <bits/stdc++.h>

using namespace std;

int t, n, c, p;

class ITS {
 public:
  // intransitive sentence
  string subj;
  string verb;

  virtual string GetSentence() const { 
    return subj + " " + verb + ".";
  }

  virtual int GetSize() const { return 2; }
};

class TS : public ITS {
 public:
  // transitive sentence
  vector<string> obj;

  string GetSentence() const override {
    string ret = subj + " " + verb + " " + obj[0];
    for (int i = 1; i < obj.size(); ++i) {
      ret += ", ";
      ret += obj[i];
    }
    ret += ".";
    return ret;
  }

  int GetSize() const { return 2 + obj.size(); }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n >> c >> p;
    vector<string> nounv, tvv, itvv, conjv;
    for (int i = 0; i < n; ++i) {
      string word, type;
      cin >> word >> type;
      if (type[0] == 'n') {
        nounv.push_back(word);
      } else if (type[0] == 't') {
        tvv.push_back(word);
      } else if (type[0] == 'i') {
        itvv.push_back(word);
      } else {
        conjv.push_back(word);
      }
    }

    p += min((int)conjv.size(), p); // borrow, later replace with conj
    
    // cout << "Starts with..." << endl;
    // cout << "nounv: " << nounv.size() << endl;
    // cout << "itvv: " << itvv.size() << endl;
    // cout << "tvv: " << tvv.size() << endl;
    // cout << "conjv: " << conjv.size() << endl;
    // cout << "period: " << p << endl;
    // cout << "comma: " << c << endl;

    vector<ITS> its_vec;
    while (nounv.size() && itvv.size() && p > 0) {
      ITS its;
      its.subj = nounv.back();
      its.verb = itvv.back();
      nounv.pop_back();
      itvv.pop_back();
      its_vec.push_back(its);
      p--;
    }
    
    vector<TS> ts_vec;
    while (nounv.size() >= 2 && tvv.size() && p > 0) {
      TS ts;
      ts.subj = nounv.back();
      ts.verb = tvv.back();
      nounv.pop_back();
      tvv.pop_back();
      ts.obj.push_back(nounv.back());
      nounv.pop_back();
      ts_vec.push_back(ts);
      p--;
    }

    // 만약 noun과 tv가 남으면 its를 ts로 변환, 이때 전체적인 길이 +1
    // 이때 period는 변화하지 않음
    while (its_vec.size() && nounv.size() && tvv.size()) {
      auto its = its_vec.back();
      its_vec.pop_back();
      itvv.push_back(its.verb);

      TS ts;
      ts.subj = its.subj;
      ts.verb = tvv.back();
      tvv.pop_back();
      ts.obj.push_back(nounv.back());
      nounv.pop_back();
      ts_vec.push_back(ts);
    }

    while (nounv.size() && itvv.size() && p > 0) {
      ITS its;
      its.subj = nounv.back();
      its.verb = itvv.back();
      nounv.pop_back();
      itvv.pop_back();
      its_vec.push_back(its);
      p--;
    }

    // 만약 아직도 noun이 남으면 min(noun.size(), C) 개수만큼 이어붙힘
    if (ts_vec.size()) {
      int nouns_can_add = min((int)nounv.size(), c);
      while (nouns_can_add--) {
        ts_vec.back().obj.push_back(nounv.back());
        c--;
        nounv.pop_back();
      }
    }

    int ans = 0;
    string ans_str = "";
    bool is_first_sentence = true;
    bool prev_connected = false;
    for (const auto& e : its_vec) {
      ans += e.GetSize();
      if (is_first_sentence) {
        ans_str += e.GetSentence();
        is_first_sentence = false;
      } else {
        if (conjv.size() && prev_connected == false) {
          ans_str.pop_back(); // remove comma
          ans_str += " " + conjv.back() + " " + e.GetSentence();
          conjv.pop_back();
          ans++;
          prev_connected = true;
        } else {
          ans_str += " " + e.GetSentence();
          prev_connected = false;
        }
      }
    }

    for (const auto& e : ts_vec) {
      ans += e.GetSize();
      if (is_first_sentence) {
        ans_str += e.GetSentence();
        is_first_sentence = false;
      } else {
        if (conjv.size() && prev_connected == false) {
          ans_str.pop_back(); // remove comma
          ans_str += " " + conjv.back() + " " + e.GetSentence();
          conjv.pop_back();
          ans++;
          prev_connected = true;
        } else {
          ans_str += " " + e.GetSentence();
          prev_connected = false;
        }
      }
    }

    cout << ans << "\n";
    cout << ans_str << "\n";
    
    // for (auto e : its_vec) {
    //   cout << "its: " << e.GetSentence() << endl;
    // }

    // for (auto e : ts_vec) {
    //   cout << "ts: " << e.GetSentence() << endl;
    // }

    // cout << "Remainings..." << endl;
    // cout << "nounv: " << nounv.size() << endl;
    // cout << "itvv: " << itvv.size() << endl;
    // cout << "tvv: " << tvv.size() << endl;
    // cout << "conjv: " << conjv.size() << endl;
    // cout << "period: " << p << endl;
    // cout << "comma: " << c << endl;
  }

  return 0;
}