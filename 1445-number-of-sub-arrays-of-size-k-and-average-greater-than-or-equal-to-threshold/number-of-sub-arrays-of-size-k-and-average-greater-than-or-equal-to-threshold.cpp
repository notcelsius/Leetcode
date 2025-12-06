class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        long long sum = 0;
        int a = 0;
        int ans = 0;
        while(a <= k-1){
            sum += arr[a];
            a++;
        }
        if(sum/k >= threshold) ans++;
        for(int i = 1; i < arr.size() - k + 1; i++){
            sum = sum - arr[i -1] + arr[i+ k -1];
            if(sum/k >= threshold) ans++;
        }
        return ans;
    }
};