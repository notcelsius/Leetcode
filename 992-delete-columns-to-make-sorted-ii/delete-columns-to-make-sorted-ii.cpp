class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int numDeletions = 0;
        int n = (int)strs.size();
        int m = (int)strs[0].size();

        // fixed[i] == true means strs[i] < strs[i+1] is already determined
        vector<bool> fixed(n - 1, false);

        int c = 0;
        while (c < m) {
            bool deleteCol = false;

            // 1) Check if keeping this column would break any *undecided* adjacent pair
            int r = 0;
            while (r < n - 1) {
                if (!fixed[r]) {
                    char char1 = strs[r][c];
                    char char2 = strs[r + 1][c];
                    if (char1 > char2) {
                        deleteCol = true;
                        break;
                    }
                }
                r++;
            }

            if (deleteCol) {
                numDeletions++;
                c++;
                continue; // deleted column, do NOT update fixed[]
            }

            // 2) Column is safe: use it to "lock in" any pairs that become strictly increasing
            r = 0;
            while (r < n - 1) {
                if (!fixed[r]) {
                    char char1 = strs[r][c];
                    char char2 = strs[r + 1][c];
                    if (char1 < char2) {
                        fixed[r] = true;
                    }
                }
                r++;
            }

            // 3) Early stop if all adjacent pairs are fixed
            bool fullySorted = true;
            for (bool f : fixed) {
                if (!f) {
                    fullySorted = false;
                    break;
                }
            }
            if (fullySorted) break;

            c++;
        }

        return numDeletions;
    }
};
