class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            bool divisible = true;
            int x = i;
            while (x > 0) {
                int d = x % 10;
                if (d == 0 || i % d != 0) {
                    divisible = false;
                    break;
                }
                x /= 10;
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