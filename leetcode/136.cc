// 136. Single Number
// https://leetcode.com/problems/single-number/

// Naive Way
class Solution {
 public:
  int record[60001];

  int Convert(int x) {
    if (x < 0) return -x + 30000;
    return x;
  }

  int singleNumber(vector<int>& nums) {
    for (int i = 0; i < 60001; ++i) record[i] = 0;

    for (auto num : nums) {
      ++record[Convert(num)];
    }

    int ans;
    for (int i = 0; i < 60001; ++i) {
      if (record[i] == 1) {
        ans = i;
        if (i > 30000) {
          ans -= 30000;
          ans = -ans;
        }
        break;
      }
    }
    return ans;
  }
};

// XOR way
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (auto num : nums) {
      ans ^= num;
    }
    return ans;
  }
};