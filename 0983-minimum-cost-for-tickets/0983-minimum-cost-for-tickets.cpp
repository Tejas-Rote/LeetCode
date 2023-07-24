class Solution {
public:
//     int helper(int i, int till, int cost, vector<int>& d, vector<int>& c, vector<vector<int>>& dp) {
//         if (i == d.size()) {
//             return cost;
//         }

//         if (dp[i][till] != -1) {
//             return dp[i][till];
//         }

//         if (till < d[i]) {
//             int one = helper(i + 1, d[i], cost + c[0], d, c, dp);
//             int seven = helper(i + 1, d[i] + 6, cost + c[1], d, c, dp);
//             int thirty = helper(i + 1, d[i] + 29, cost + c[2], d, c, dp);
//             dp[i][till] = min(one, min(seven, thirty));
//         } else {
//             dp[i][till] = helper(i + 1, till, cost, d, c, dp);
//         }

//         return dp[i][till];
    // }

        int helper(int ind  , vector<int>&costs , unordered_set<int>&days,vector<int>&dp )
         {
            if(ind> 365)
            {
                return 0;
            }
            if(dp[ind]!=-1)
            {
                return dp[ind];
            }
               //Well if the day is not present we will not be tarvelling
               //so this is not_pick condition
            if(days.find(ind) == days.end()) 
            {
               return helper(ind+1  ,costs ,days,dp );
            }
          //if the day is present then we will pick and add the cost
            int day1 = costs[0] + helper(ind+1  , costs , days ,dp);
            int day7 = costs[1] + helper(ind+7  , costs , days ,dp);
            int day30 = costs[2] + helper(ind+30  , costs , days,dp );

            return dp[ind] = min(day1 ,min (day7 , day30));
         }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int n = days.size();
        // vector<vector<int>> dp(n + 1, vector<int>(367, -1));
        // return helper(0, 0, 0, days, costs, dp);
        int n = days.size();
        unordered_set<int>temp;
        vector<int>dp(366,-1);
        for(int i = 0 ; i < n ; i++)
        {
           temp.insert(days[i]);
        }

       return helper(days[0]  ,costs,temp,dp);
        
    }
};