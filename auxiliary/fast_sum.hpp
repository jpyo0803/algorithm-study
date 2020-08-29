#ifndef ALGORITHM_STUDY_FAST_SUM_HPP
#define ALGORITHM_STUDY_FAST_SUM_HPP

int FastSum(int n) {
  if (n == 1) return 1;
  if (n % 2) return FastSum(n - 1) + n;
  return FastSum(n / 2) * 2 + (n / 2) * (n / 2);
}

#endif