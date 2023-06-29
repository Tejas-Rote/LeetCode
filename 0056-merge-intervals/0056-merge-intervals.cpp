class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        int n = intervals.size();
        int m = 2;
        sort(intervals.begin(), intervals.end());
        
        
        for(int i=0;i<n;i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }else {
                // the current interval lies between the last interval then update the interval end value
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }
        }
        
        return ans;
    }
};