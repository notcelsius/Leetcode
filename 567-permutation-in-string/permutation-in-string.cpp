class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> freq;
        for (char c : s1) freq[c]++;

        int matched = 0;
        int l = 0;

        for (int r = 0; r < (int)s2.size(); r++) {
            char rightChar = s2[r];

            // expand window: include rightChar
            if (freq.count(rightChar)) {
                freq[rightChar]--;
                if (freq[rightChar] == 0) matched++;
            }

            // if we matched all unique chars, we found a permutation
            if (matched == (int)freq.size()) return true;

            // shrink window when it reaches size s1
            if (r - l + 1 >= (int)s1.size()) {
                char leftChar = s2[l++];
                if (freq.count(leftChar)) {
                    if (freq[leftChar] == 0) matched--;
                    freq[leftChar]++;  // ALWAYS put it back
                }
            }
        }

        return false;
    }
};
