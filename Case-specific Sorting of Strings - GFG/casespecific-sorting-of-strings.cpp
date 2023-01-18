//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string ans ="";
        vector<char> l;
        vector<char> u;
        
        for(int i=0;i<n;i++){
             if(str[i]>=65 && str[i]<=90)
            l.push_back(str[i]);  
            
            if(str[i]>=97 && str[i]<=122)
            u.push_back(str[i]); 
        }
        
        
        sort(l.begin(), l.end());
        sort(u.begin(), u.end());
        
        int j=0, k=0;
        for(int i=0;i<n;i++){
            if(str[i]>=65 && str[i]<=90){
                ans +=l[j];
                j++;
            }
            if(str[i]>=97 && str[i]<=122){
                ans+= u[k];
                k++;
            }
            
        }
        
        // cout<<"ans is"<< ans<<endl;
        
        return ans;
        
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends