class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int recolors = 0;
        int minRecolors = INT_MAX;
        int l = 0;
        for (int r = 0; r < blocks.size(); r++) {
            if (blocks[r] == 'W') {
                recolors++;
            }
            while (r - l + 1 > k) {
                if (blocks[l] == 'W') {
                    recolors--;
                }
                l++;
            }
            if (r - l + 1 == k) {
                minRecolors = min(minRecolors, recolors);
            }
            
        }
        return minRecolors;
    }
};