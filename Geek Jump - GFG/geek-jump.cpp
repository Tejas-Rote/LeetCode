//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp (n, 0);
        dp[0] = 0;
        // dp[1] = abs(height[0] - height[1]);
        // cout<<dp[0] <<" "<<dp[1]<<endl;
        
        // for(int i=2;i<=n;i++){
        //     cout<<height[i]<<" "<< abs(height[i] - dp[i-1])<<" "<<abs(height[i] - dp[i-2])<<"->";
        //     dp[i] = min(abs(height[i] - dp[i-1]), abs(height[i] - dp[i-2]));
        //     cout<<i<<" "<< dp[i]<<endl;
        // }
        
        // return dp[n];
        
        int res =0;
        for(int i=1;i<n;i++){
            int fs = dp[i-1] + abs(height[i] - height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = dp[i-2] + abs(height[i] - height[i-2]);
            }
            dp[i] = min(fs, ss);
        }
        
        return dp[n-1];
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends