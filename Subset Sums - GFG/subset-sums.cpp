//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void helper(vector<int>&ans, vector<int>&arr, int N , int index, int sum){
        if(index == N){
            ans.push_back(sum);
            return;
        }
        
        
        helper(ans, arr, N, index+1, sum);
        helper(ans, arr, N, index+1, sum+arr[index]);
    }
    
    // void subsum(int sum ,  vector<int> &ans, vector<int> arr, int N, int index){
    //     if(index == N){
    //         ans.push_back(sum);
    //         return;
    //     }
        
    //     subsum(sum+arr[index], ans, arr, N, index+1);
    //     subsum(sum, ans, arr, N, index+1);
        
    // }
    
    
    vector<int> subsetSums(vector<int> arr, int N)
    {   
        vector<int> ans;
        int sum = 0;
        helper(ans, arr, N,0 , sum);
        
        return ans; 
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends