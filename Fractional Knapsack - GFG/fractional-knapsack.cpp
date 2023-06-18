//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool myCmp(Item a, Item b)
    {
    	double r1 = (double)a.value / a.weight;
    	double r2 = (double)b.value / b.weight;
    	return r1 > r2;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        
        
        sort(arr, arr + n, myCmp);
    	double  res = 0.0;
    	for(int i = 0; i < n; i++)
    	{
    		if(arr[i].weight <= W)
    		{
    			res += arr[i].value;
    			W = W - arr[i].weight;
    		}
    		else
    		{
    			res += arr[i].value * ((double) W / arr[i].weight);
    			break;
    		}
    	}

	    return res;
	
        // // double ratio[n];
        // double ans;
        // vector<pair<double, pair<int,int>>> f;
        // for(int i=0;i<n;i++){
        //     double ratio= arr[i].value/arr[i].weight;
        //     f.push_back({ratio, {arr[i].value, arr[i].weight}});
        // }
        // sort(f.begin(), f.end());
        // reverse(f.begin(), f.end());
        // // for(int i=0;i<n;i++){
        // //     cout<<f[i].first<<" -> "<<f[i].second.first<<" / "<<f[i].second.second<<endl;
        // // }

        // double curw = W;
        // int  j=0;
        // for(int i=0;i<n;i++){
        //     if(f[i].second.second <= curw){
        //         curw -= f[i].second.second;
        //         ans += f[i].second.first; 
        //         // cout<<ans<<"-"<<curw<<"->";
        //     }else {
        //         ans += (f[i].second.first) * (curw/f[i].second.second);
        //         // cout<<ans<<endl;
        //         return ans;
        //     }
        // }
        // return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends