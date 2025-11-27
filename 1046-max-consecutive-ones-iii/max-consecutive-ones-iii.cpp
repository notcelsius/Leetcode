class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxW = 0;
        int num0 = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                num0++;
            }

            while (num0 > k) {
                if (nums[l] == 0) {
                    num0--;
                }
                l++;
            }

            maxW = max(maxW, r - l + 1);
        }
        return maxW;
        
    }
};