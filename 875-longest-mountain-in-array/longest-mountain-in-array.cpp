class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if (arr.size() < 3) {
            return 0;
        }
        int maxLength = 0;
        int i = 0;
        while (i < arr.size() - 1) {
            int l = 0;
            int r = 0;
            while (i < arr.size() - 1 && arr[i] < arr[i+1]) {
                l++;
                i++;
            }
            if (l == 0) {
                i++;
                continue;
            }
            while (i < arr.size() - 1 && arr[i] > arr[i+1]) {
                r++;
                i++;
            }
            if (r == 0) {
                i++;
                continue;
            }
            maxLength = max(maxLength, r + l + 1);
        }
        return maxLength;
    }
};