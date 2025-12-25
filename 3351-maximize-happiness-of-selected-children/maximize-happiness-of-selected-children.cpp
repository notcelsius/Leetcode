class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0;
        priority_queue<int> pq;
        for (int children: happiness) {
            pq.push(children);
        }
        for (int i = 0; i < k; i++) {
            
            sum += pq.top() - i >= 0 ? pq.top() - i: 0;
            pq.pop();
        }
        return sum;
    }
};