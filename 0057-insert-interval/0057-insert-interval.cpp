class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

          vector<vector<int>> ans;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (intervals[i][1] < newInterval[0]) {
                // current interval starts first & not covered by newInterval, add intervals[i] to ans
                // [curInterval]
                //                      [newInterval]
                ans.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                // newInterval starts first and not covered by current interval
                // add newInterval to ans and set newInterval = curInterval
                //                       [curInterval]
                // [newInterval]
                ans.push_back(newInterval);
                newInterval = intervals[i];
            } else if (intervals[i][1] >= newInterval[0] || intervals[i][0] <= newInterval[1]) {
                // they are overlapped, merge them
                // [curInterval]
                //        [newInterval]
                // or
                // [newInterval]
                //        [curInterval]
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        // add the last interval
        ans.push_back(newInterval);
        return ans;
        
    }
}; 