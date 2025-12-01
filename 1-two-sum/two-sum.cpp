class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> valToIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (valToIndex.count(target-nums[i])) {
                return {i, valToIndex[target-nums[i]]};
            }
            valToIndex[nums[i]] = i;
        }
        return {};
    }
};