//
// Created by pyo on 2020-07-20.
//

#ifndef ALGORITHM_STUDY_AUXILIARY_SEARCH_KMP_HPP_
#define ALGORITHM_STUDY_AUXILIARY_SEARCH_KMP_HPP_

#include <string>
#include <vector>
#include <iostream>

std::vector<int> SearchKMP(std::string& hay, std::string& key) {
  std::vector<int> ret;

  int n = hay.length();
  int m = key.length();

  std::vector<int> pi(m, 0);

  int begin = 1, matched = 0;

  while (begin + matched < m) {
    if (key[begin + matched] == key[matched]) {
      matched += 1;
      pi[begin + matched - 1] = matched;
    } else {
      if (matched == 0) {
        begin += 1;
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }

  begin = matched = 0;
  while (begin <= n - m) {
    if (matched < m && hay[begin + matched] == key[matched]) {
      matched += 1;
      if (matched == m) {
        ret.push_back(begin);
      }
    } else {
      if (matched == 0) {
        begin += 1;
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }

  return ret;
}

#endif //ALGORITHM_STUDY_AUXILIARY_SEARCH_KMP_HPP_
