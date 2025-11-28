class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int index = 0;
        while (index < intervals.size()) {
            int start = intervals[index][0];
            int finish = intervals[index][1];
            while (index < intervals.size() - 1 && intervals[index+1][0] <= finish) {
                index++;
                if (finish < intervals[index][1]) {
                    finish = intervals[index][1];
                }
            }
            result.push_back({start, finish});
            index++;

        }
        return result;
    }

};