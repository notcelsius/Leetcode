using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
  bool circularArrayLoop(vector<int> &nums) {
    int n = nums.size();
    if (n == 1) {
      return false;
    }
    for (int start = 0; start < n; start++) {
      if (nums[start] == 0) {
        continue;
      }
      int dir = nums[start] > 0 ? 1: -1;
      int slow = start;
      int fast = start;

      while (true) {
        int nextSlow = ((slow + nums[slow]) % n + n) % n;
        if (nextSlow == slow) break; 
        if ((nums[nextSlow] > 0 ? 1 : -1) != dir) break;

        int nextFast = ((fast + nums[fast]) % n + n) % n;
        if (nextFast == fast) { break; } // self-loop
        else if ((nums[nextFast] > 0 ? 1 : -1) != dir) break;

        int nextFast2 = ((nextFast + nums[nextFast]) % n + n) % n;
        if (nextFast2 == nextFast) { break; } // self-loop
        else if ((nums[nextFast2] > 0 ? 1 : -1) != dir) break;

        slow = nextSlow;
        fast = nextFast2;

        if (slow == fast) {
          return true;
        }

      }

      int idx = start;
      while (nums[idx] != 0 && (nums[idx] > 0 ? 1 : -1) == dir) {
        int nextIdx = ((idx + nums[idx]) % n + n) % n;
        nums[idx] = 0;
        if (nextIdx == idx) break;
        idx = nextIdx;
      }
    }
    return false;
  }
};
