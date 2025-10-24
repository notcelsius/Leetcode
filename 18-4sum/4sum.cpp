#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  static vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    int n = (int)nums.size();
    if (n < 4) return res;

    sort(nums.begin(), nums.end());
    long long T = (long long)target;

    for (int i = 0; i <= n - 4; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      for (int j = i + 1; j <= n - 3; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;

        int l = j + 1, r = n - 1;
        while (l < r) {
          long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
          if (sum == T) {
            res.push_back({nums[i], nums[j], nums[l], nums[r]});
            ++l; --r;
            while (l < r && nums[l] == nums[l - 1]) ++l;      // skip dup L
            while (l < r && nums[r] == nums[r + 1]) --r;      // skip dup R
          } else if (sum < T) {
            ++l;
          } else {
            --r;
          }
        }
      }
    }
    return res;
  }
};
