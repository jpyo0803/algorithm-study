//
// Goldbach's conjecture
// Problem: https://www.acmicpc.net/problem/6588
//

#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

int N, a, b;
const int NUM_PN{1000000};
vector<int> prime_numbers;
unordered_set<int> is_prime;

bool eras[NUM_PN];
void find_primes() {
  int curr_pn = 2;
  while (curr_pn < NUM_PN) {
    prime_numbers.push_back(curr_pn);
    is_prime.insert(curr_pn);
    for (int i = curr_pn; i < NUM_PN; i += curr_pn) {
      eras[i] = true;  // not prime
    }
    while (eras[curr_pn]) {
      curr_pn += 1;
    }
  }
}

int main() {
  find_primes();
  while (true) {
    scanf("%d", &N);
    if (N == 0) break;
    bool is_valid = false;
    for (auto pn : prime_numbers) {
      a = pn;
      b = N - a;
      if (is_prime.find(b) != is_prime.end()) {
        is_valid = true;
        break;
      }
    }

    if (is_valid)
      printf("%d = %d + %d\n", N, a, b);
    else
      printf("Goldbach's conjecture is wrong.");
  }

  return 0;
}