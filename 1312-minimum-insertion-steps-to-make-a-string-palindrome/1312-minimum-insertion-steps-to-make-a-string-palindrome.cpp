class Solution {
public:
    int minInsertions(string s1) {
        int n=s1.size();
        int m= n;
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        // cout<<s2<<endl;

        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        vector<int> prev(n+1, 0), cur(n+1, 0);
        // for(int i=0;i<=n;i++){
        //     dp[i][0] = 0;
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

        int l=  prev[m];
        // cout<<l<<endl;
        int res; 
        res = n- l;
        return res;
    }
};