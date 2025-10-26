using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class Solution {
public:
  static int findUnsortedSubarray(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r && nums[l] <= nums[l+1]) {
      l++;
    }
    if (l == r) {
      return 0;
    }
    while (r > 0 && nums[r] >= nums[r-1]) {
      r--;
    }
    int submin = nums[l];
    int submax = nums[r];
    for (int i = l; i <= r; i++) {
      submin = std::min(nums[i], submin);
      submax = std::max(nums[i], submax);
    }
    while (l > 0 && nums[l-1] > submin) {
      l--;
    }
    while (r < nums.size() - 1 && nums[r+1] < submax) {
      r++;
    }
    return r - l + 1;
  }
};
