//
// FANMEETING
// Link: https://www.algospot.com/judge/problem/read/FANMEETING
//

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int C;
char input[200001];

void AddTo(vector<int>& a, const vector<int>& b, int k) {  // a += b * 10^k
  a.resize(max<int>(a.size(), b.size()) + k, 0);
  for (int i = 0; i < b.size(); i++) a[i + k] += b[i];
}

void SubFrom(vector<int>& a, const vector<int>& b) {
  for (int i = 0; i < b.size(); i++) a[i] -= b[i];
}

vector<int> Multiply(const vector<int>& a, const vector<int>& b) {
  vector<int> c(a.size() + b.size() + 1, 0);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      c[i + j] += a[i] * b[j];
    }
  }
  return c;
}

vector<int> Karatsuba(const vector<int>& a, const vector<int>& b) {
  if (a.size() < b.size())
    return Karatsuba(b, a);  // To keep size of a > size of b
  if (a.size() == 0 || b.size() == 0) return vector<int>();
  if (a.size() < 50) return Multiply(a, b);  // base case

  int half = a.size() / 2;
  vector<int> a0(a.begin(), a.begin() + half);
  vector<int> a1(a.begin() + half, a.end());
  vector<int> b0(b.begin(), b.begin() + min<int>(half, b.size()));
  vector<int> b1(b.begin() + min<int>(half, b.size()), b.end());

  vector<int> z2 = Karatsuba(a1, b1);
  vector<int> z0 = Karatsuba(a0, b0);

  AddTo(a0, a1, 0);
  AddTo(b0, b1, 0);
  vector<int> z1 = Karatsuba(a0, b0);
  SubFrom(z1, z2);
  SubFrom(z1, z0);

  vector<int> ret;
  AddTo(ret, z2, half * 2);
  AddTo(ret, z1, half);
  AddTo(ret, z0, 0);
  return ret;
}

int hug(vector<int>& members, vector<int>& fans) {
  int N = members.size();
  int M = fans.size();
  int bigger = N > M ? N : M;
  int smaller = N < M ? N : M;
  vector<int> out = Karatsuba(members, fans);
  int hug_count = 0;
  for (int i = smaller - 1; i < bigger; i++) {
    if (!out[i]) hug_count++;
  }
  return hug_count;
}

int main() {
  scanf("%d", &C);
  for (int c = 0; c < C; c++) {
    int N, M;
    scanf("%s", input);
    N = strlen(input);
    vector<int> members(N, 0);
    for (int i = 0; i < N; i++) members[i] = input[i] == 'M';
    scanf("%s", input);
    M = strlen(input);
    vector<int> fans(M, 0);
    for (int i = 0; i < M; i++) fans[M - i - 1] = input[i] == 'M';
    printf("%d\n", hug(members, fans));
  }
  return 0;
}