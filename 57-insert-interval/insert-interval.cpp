class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int start = newInterval[0];
        int end = newInterval[1];
        vector<vector<int>> mergedIntervals;
        while (i < intervals.size() && start > intervals[i][1]) {
            mergedIntervals.push_back(intervals[i++]);
        }
        while (i < intervals.size() && end >= intervals[i][0]) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;
        }
        mergedIntervals.push_back({start,end});
        while (i < intervals.size()) {
            mergedIntervals.push_back(intervals[i++]);
        }
        return mergedIntervals;
    }
};