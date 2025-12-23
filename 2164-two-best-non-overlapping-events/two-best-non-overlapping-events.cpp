class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();

        // 1) Sort by start time
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        // 2) suffixMax[i] = max value from i to end
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(suffixMax[i + 1], events[i][2]);
        }

        int ans = 0;

        // 3) Try each event as the first event
        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int end   = events[i][1];
            int val   = events[i][2];

            // Option 1: take only this event
            ans = max(ans, val);

            // Option 2: take this event + best non-overlapping event
            // Need start >= end + 1  => start > end
            int left = i + 1, right = n - 1;
            int idx = -1;

            // Binary search for first event with start > end
            while (left <= right) {
                int mid = (left + right) / 2;
                if (events[mid][0] > end) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (idx != -1) {
                ans = max(ans, val + suffixMax[idx]);
            }
        }

        return ans;
    }
};
