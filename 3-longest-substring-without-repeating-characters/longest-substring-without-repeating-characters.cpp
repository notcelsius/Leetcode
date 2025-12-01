class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int maxLength = 0;
        int noDups = 0;
        for (int r = 0; r < s.size(); r++) {
            if (mp.count(s[r]) == 1) {
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};