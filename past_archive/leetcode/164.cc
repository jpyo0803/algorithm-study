//
// Maximum Gap
// Problem: https://leetcode.com/problems/maximum-gap/
//

class Solution {
 public:
  int* CountSort(int nums[], int size, uint64_t exp) {
    int output[size];
    int count_arr[10] = {0};

    for (int i = 0; i < size; i++) {
      count_arr[(nums[i] / exp) % 10] += 1;
    }

    for (int i = 1; i < 10; i++) {
      count_arr[i] += count_arr[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
      output[count_arr[(nums[i] / exp) % 10] - 1] = nums[i];
      count_arr[(nums[i] / exp) % 10] -= 1;
    }

    for (int i = 0; i < size; i++) {
      nums[i] = output[i];
    }
    return nums;
  }

  int* RadixSort(int nums[], int size) {
    int max_num = 0;
    for (int i = 0; i < size; i++) {
      max_num = max(max_num, nums[i]);
    }

    for (uint64_t exp = 1; max_num / exp > 0; exp *= 10) {
      nums = CountSort(nums, size, exp);
    }
    return nums;
  }

  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    }

    int size = nums.size();
    int* sorted_arr = RadixSort(&nums[0], size);

    int ans = 0;
    for (int i = 1; i < size; i++) {
      ans = max(ans, sorted_arr[i] - sorted_arr[i - 1]);
    }
    return ans;
  }
};