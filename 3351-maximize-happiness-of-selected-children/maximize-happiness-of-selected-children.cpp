class Solution {
public:
long long maximumHappinessSum(vector<int>& happiness, int k) {
    sort(happiness.begin(), happiness.end(), greater<int>());
    
    long long sum = 0;
    for (int i = 0; i < k && i < happiness.size(); i++) {
        long long val = (long long)happiness[i] - i;
        if (val <= 0) break;   // early exit optimization
        sum += val;
    }
    return sum;
}

};