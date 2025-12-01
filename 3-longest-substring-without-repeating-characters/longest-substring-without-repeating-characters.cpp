class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> freq;
        int l = 0;
        int maxLength = 0;
        for (int r = 0; r < s.size(); r++) {
            if (freq.count(s[r]) >= 1) {
                while (freq.count(s[r]) >= 1) {
                    freq.erase(s[l]);
                    l++;
                }
            }
            freq.insert(s[r]);
            maxLength =  max(r - l + 1, maxLength);
        }
        return maxLength;
    }
};