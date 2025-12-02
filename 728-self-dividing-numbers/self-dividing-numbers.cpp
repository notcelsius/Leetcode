class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            bool divisible = true;
            string num = to_string(i);
            for (int j = 0; j < num.size(); j++) {
                int d = num[j] - '0';
                if (d == 0 || i % d != 0) {
                    divisible = false;
                    break;
                }
            }
            if (divisible) {
                res.push_back(i);
            }
            else {
                continue;
            }
        }
        return res;
    }
};