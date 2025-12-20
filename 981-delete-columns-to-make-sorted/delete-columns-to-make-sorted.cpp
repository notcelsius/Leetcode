class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int numDelete = 0;
        for (int c = 0; c < strs[0].size(); c++) {
            char curr = strs[0][c];
            for (int r = 0; r < strs.size(); r++) {
                char curr1 = strs[r][c];
                if (curr > curr1) {
                    numDelete++;
                    break;
                }
                curr = curr1;
            }
        }
        return numDelete;
    }
};