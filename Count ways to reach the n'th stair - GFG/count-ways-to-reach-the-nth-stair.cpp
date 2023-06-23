//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    #define mod 1000000007
    //Function to count number of ways to reach the nth stair.
    
    // int f (int n , vector<int> dp, int &cnt){
    //     // if(n==0){
    //     //     cnt++;
    //     //     return n;
    //     // }
        
    //     // if(dp[n] != -1){
    //     //     return dp[n];
    //     // }else{
    //     //     if(n>=2 ){
    //     //         return dp[n] = f(n-2, dp , cnt);
    //     //     }
    //     //     if(n>=1){
    //     //         return dp[n] =f(n-1, dp , cnt);
    //     //     }
    //     // }
    // }
    
    int solve(int n, vector<int>&dp){
        
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            dp[i]=dp[i-1]%mod+dp[i-2]%mod;
        }
        return (dp[n]%mod);
    }
    
    
    int countWays(int n)
    {
        // int cnt =0;
        
        // vector<int> memo(n+1, -1);
        // f(n, memo , cnt);
        // cout<<cnt<<endl;
        // for(int i=0;i<n+1;i++){
        //     cout<<memo[i]<<" ";
        // }
        // return cnt;
        
        int prev2 = 1;
        int prev = 1;
          
        for(int i=2; i<=n; i++){
            int cur_i = (prev2%mod)+ (prev%mod);
            prev2 = prev;
            prev= cur_i;
         }
        // cout<<prev;
        return prev%mod;
        
        // your code here
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