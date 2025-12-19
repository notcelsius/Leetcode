class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        int numPalindromes = 0;
        bool hasOdd = false;
        for (char c: s) {
            freq[c]++;
        }
        for (auto& pair: freq) {
            if (pair.second % 2 == 1) {
                hasOdd = true;
            }
            numPalindromes += (pair.second/2 * 2);
        }
        if (hasOdd == true) {
            numPalindromes++;
        }
        return numPalindromes;
    }
};