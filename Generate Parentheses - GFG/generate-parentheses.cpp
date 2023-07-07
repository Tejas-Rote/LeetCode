//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    private:
     void helper(int i,int j,int n,vector<string> &v,string s){
        if(i>n || j>n) return;
        if(i==n && j==n){
            v.push_back(s);
            return;
        }
        s+='(';
        helper(i+1,j,n,v,s);
        s.pop_back();
        if(i>j){
            s+=')';
            helper(i,j+1,n,v,s);
            s.pop_back();
        }
    }
    
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string> v;
        helper(0,0,n,v,"");
        return v;
        // Your code goes here 
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends