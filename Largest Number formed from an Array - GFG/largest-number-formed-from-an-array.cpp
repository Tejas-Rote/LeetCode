//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	
   static bool compare(string a, string b)
    {
        string value1 = a+b;
        string value2 =b+a;
        return value1 > value2;
    }



	string printLargest(vector<string> &arr) {
	    long int num;
	    long int max_num = INT_MIN;
	    int  n = arr.size();
	    string s="",ans="";

	   sort(arr.begin(), arr.end(), compare);
	   //reverse(arr.begin(), arr.end());
	   
	   for( int i=0;i<n;i++){
	       //cout<<arr[i]<<" ";
	       ans +=arr[i];
	   }
	   
	   return ans;
	   
	   
	   
	   
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends