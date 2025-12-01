class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        backtrack(0, "", digits);
        return res;
    }

    void backtrack(int i, string curr, string& digits) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for (char c: chars) {
            backtrack(i + 1, curr + c, digits);
        }
    }
};