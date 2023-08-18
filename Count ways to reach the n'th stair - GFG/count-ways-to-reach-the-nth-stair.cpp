//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    
    int helper(int ind, int n, vector<int> &dp){
        if( ind == n){
            return 1;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        int one = helper(ind+1, n, dp);
        int two=0;
        if(ind+2 <=n){
            two = helper(ind+2, n, dp);
        }
        
        return dp[ind] = (one + two)% 1000000007;
        
    }
    int countWays(int n)
    {
        vector<int> dp(n+1, -1);
        return helper(0, n, dp);
        
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends