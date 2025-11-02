class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int sum = 0;
        int shortest = INT_MAX;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            if (sum >= target) {
                while (sum - nums[l] >= target) {
                    sum -= nums[l];
                    l++;
                }
                shortest = min(shortest, r - l + 1);
            }
        }

        if (shortest == INT_MAX) {
            return 0;
        }
        else {
            return shortest;
        }
    }
};