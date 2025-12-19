class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int cost = 0;
        // while not on the same row
        int i = startPos[0];
        int j = homePos[0];
        while (i != j) {
            if (i < j) {
                i++;
                cost += rowCosts[i];
            }
            else {
                i--;
                cost += rowCosts[i];
            }
        }
        // while not on same col
        i = startPos[1];
        j = homePos[1];
        while (i != j) {
            if (i < j) {
                i++;
                cost += colCosts[i];
            }
            else {
                i--;
                cost += colCosts[i];
            }
        }

        return cost;
    }
};