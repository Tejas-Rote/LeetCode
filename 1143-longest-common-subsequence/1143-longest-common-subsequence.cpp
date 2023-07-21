class Solution {
public:
    int helper(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        if(ind1<0|| ind2<0){
            return 0;
        }
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        if(s1[ind1]== s2[ind2]){
            return dp[ind1][ind2] = 1 + helper(ind1-1, ind2-1, s1,s2, dp);
        }
        
        return dp[ind1][ind2] = max(helper(ind1-1, ind2, s1, s2, dp), helper(ind1, ind2-1, s1, s2, dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        // int n = text1.size();
        // int m = text2.size();
        //memo
        // vector<vector<int>> dp(n+1 , vector<int> (m+1, -1));
        // return helper(n-1, m-1, text1, text2, dp);
        
        // tabulation
        int n=s1.size();
        int m=s2.size();

        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        vector<int> prev(m+1, 0), cur(m+1, 0);
        // for(int i=0;i<=n;i++){
        //     prev[0] = 0;
        // }
        // for(int i=0;i<=m;i++){
        //     dp[0][i] = 0;
        // }

        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s1[ind1-1]==s2[ind2-1])
                    cur[ind2] = 1 + prev[ind2-1];
                else
                    cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
            }
            prev = cur;
        }

        return prev[m];
        
    }
};