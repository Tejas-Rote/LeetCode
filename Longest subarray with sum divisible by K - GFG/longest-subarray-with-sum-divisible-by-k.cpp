//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{

	    
        int sum=0,ans=0;
	    unordered_map<int,int>ump;
	    for(int i=0;i<n;i++){
	        sum+=arr[i];
	        int r=sum%k;
	        if(r==0)ans=max(ans,i+1);
	        if(r<0)r+=k;
	        if(ump.find(r)==ump.end()){
	            ump[r]=i;
	        }
	        else ans=max(ans,i-ump[r]);
	    }
	    return ans;
	   
	   //int max_sum = 0;
    //     for (int i = 0; i < k; i++)
    //         max_sum += arr[i];

    //     int window_sum = max_sum;
    //     for (int i = k; i < n; i++) {
    //         window_sum += arr[i] - arr[i - k];
    //         max_sum = max(max_sum, window_sum);
    //     }
    //     return max_sum;
    
    
	    

	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends