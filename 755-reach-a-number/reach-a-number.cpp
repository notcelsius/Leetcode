class Solution {
public:
    int reachNumber(int target) {
        int i = 0;
        int num = 0;
        if (target >= 0) {
            while (num != target) {
                i++;
                num += i;
                if (num > target && target % 2 == 0 && num  % 2 == 0) {
                    return i;
                }
                else if (num > target && target % 2 == 1 && num  % 2 == 1) {
                    return i;
                }
            }   
        }
        else {
            while (num != target) {
                i--;
                num += i;
                if (num < target && num % 2 == 0 && target % 2 == 0) {
                    return abs(i);
                }
                else if (num < target && num % 2 == -1 && target % 2 == -1) {
                    return abs(i);
                }
            } 
        }
        
        return abs(i);
    }
};