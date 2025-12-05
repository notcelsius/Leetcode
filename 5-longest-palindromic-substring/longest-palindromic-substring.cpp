class Solution {
public:
    string longestPalindrome(string s) {
        int resLen = 0;
        int resIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            // odd case
            int l = i;
            int r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (resLen < r - l + 1) {
                    resIndex = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
            // even case
            l = i;
            r = i + 1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (resLen < r - l + 1) {
                    resIndex = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
            
        }
        return s.substr(resIndex, resLen);
    }
};