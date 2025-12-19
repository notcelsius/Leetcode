class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int startRow = startPos[0];
        int startCol = startPos[1];

        int endRow = homePos[0];
        int endCol = homePos[1];

        int ans = 0;
        if (startRow < endRow) {
            for (int i = startRow + 1; i <= endRow; i++) {
                ans += rowCosts[i];
            }
        } else {
            for (int i = startRow - 1; i >= endRow; i--) {
                ans += rowCosts[i];
            }
        }
        if (startCol < endCol) {
            for (int i = startCol + 1; i <= endCol; i++) {
                ans += colCosts[i];
            }
        } else {
            for (int i = startCol - 1; i >= endCol; i--) {
                ans += colCosts[i];
            }
        }
        return ans;
    }
};