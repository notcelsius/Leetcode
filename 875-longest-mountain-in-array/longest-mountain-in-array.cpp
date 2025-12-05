class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if (arr.size() < 3) {
            return 0;
        }   
        int maxLength = 0;
        for (int i = 1; i < arr.size() - 1; i++) {
            int l = i;
            int r = i;
            bool decrease = false;
            bool increase = false;
            while (l >= 1 && arr[l] > arr[l-1]) {
                l--;
                decrease = true;
            }
            while (r < arr.size() - 1 && arr[r] > arr[r+1]) {
                r++;
                increase = true;
            }
            if (increase && decrease) {
                maxLength = max(maxLength, r - l + 1);
            }
           
        }
        return maxLength;
    }
};