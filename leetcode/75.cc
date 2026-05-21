// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/

class Solution {
 public:
  vector<int> tmp_;

  void MergeSort(vector<int>& nums, int l, int r) {
    if (l == r) {
      tmp_[l] = nums[l];
      return;
    }

    int m = (l + r) / 2;
    MergeSort(nums, l, m);
    MergeSort(nums, m + 1, r);

    int i = l, j = l;
    int k = m + 1;
    while (i <= r) {
      if (j <= m && k <= r) {
        if (tmp_[j] < tmp_[k]) {
          nums[i++] = tmp_[j++];
        } else {
          nums[i++] = tmp_[k++];
        }
      } else {
        if (j <= m) {
          nums[i++] = tmp_[j++];
        } else {
          nums[i++] = tmp_[k++];
        }
      }
    }

    for (int i = l; i <= r; ++i) {
      tmp_[i] = nums[i];
    }
  }

  void sortColors(vector<int>& nums) {
    tmp_ = vector<int>(nums.size());
    MergeSort(nums, 0, nums.size() - 1);
  }
};