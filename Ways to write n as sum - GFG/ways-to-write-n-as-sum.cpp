//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int helper(int cur, int n , vector<vector<int>> & dp){
        if(n<0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        
        if(cur> n){
            return 0;
        }
        
        if(dp[cur][n] != -1){
            return dp[cur][n];
        }
        int nconsider = helper(cur+1, n, dp);
        int consider = 0;
        if(n >= cur){
            consider = helper(cur , n-cur, dp);
        }
        
        return dp[cur][n] = (consider + nconsider)% 1000000007;
    }
    
    int countWays(int n)
    {
        vector<vector<int>> dp (n+1, vector<int>(n+1, -1));
        return helper(1, n, dp)-1 ; 
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    //taking number of testcases
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.countWays(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends