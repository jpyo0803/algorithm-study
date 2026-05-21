// 15. 3Sum
// https://leetcode.com/problems/3sum/

// First Try (Noy so smart)
int nc[400010];

class Solution {
 public:
  static int Map(int x) { return x < 0 ? -x + 200000 : x; }

  static int Remap(int x) { return x > 200000 ? -(x - 200000) : x; }

  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    for (int i = 0; i < 400010; ++i) nc[i] = 0;
    vector<int> un;

    for (int i = 0; i < nums.size(); ++i) {
      int cn = Map(nums[i]);
      if (nc[cn] == 0) un.push_back(nums[i]);
      ++nc[cn];
    }

    sort(un.begin(), un.end());

    for (int i = 0; i < un.size(); ++i) {
      int cni = Map(un[i]);
      if (nc[cni] > 0) {
        --nc[cni];
        for (int j = i; j < un.size(); ++j) {
          int cnj = Map(un[j]);
          if (nc[cnj] > 0) {
            --nc[cnj];
            int cntr = -(un[i] + un[j]);
            int cnk = Map(cntr);
            if (nc[cnk] > 0 && un[j] <= cntr) {
              ans.push_back({un[i], un[j], cntr});
            }
            ++nc[cnj];
          }
        }
        ++nc[cni];
      }
    }
    return ans;
  }
};