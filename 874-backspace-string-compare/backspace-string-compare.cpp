class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int bs1 = 0;
        int bs2 = 0;
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    i--;
                    bs1++;
                }
                else if (bs1 > 0) {
                    i--;
                    bs1--;
                }
                else {
                    break;
                }
            }

            while (j >= 0) {
                if (t[j] == '#') {
                    j--;
                    bs2++;
                }
                else if (bs2 > 0) {
                    j--;
                    bs2--;
                }
                else {
                    break;
                }
            }

            char c1 = (i >= 0) ? s[i] : '\0';
            char c2 = (j >= 0) ? t[j] : '\0';

            if (c1 != c2) {
                return false;
            }
            i--;
            j--;

        }
        return true;
    }
};