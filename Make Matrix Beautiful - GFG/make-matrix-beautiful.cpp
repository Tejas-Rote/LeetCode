//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int> rsum;
        vector<int> csum;
        int temp1,temp2;
        for(int i=0;i<matrix.size();i++){
            temp1 = temp2 =0;
            for(int j=0;j<matrix.size();j++){
                temp1+=matrix[i][j];
            }
            
            rsum.push_back(temp1);
            
            for(int k=0;k<matrix.size();k++){
                temp2+=matrix[k][i];
            }
            csum.push_back(temp2);
            
            
        }
        
        int Mrow = *max_element(rsum.begin() , rsum.end());
        int Mcol = *max_element(csum.begin(), csum.end());
        // cout<<Mrow<<" "<<Mcol<<endl;
        
        int target = max(Mrow, Mcol);
        
        
        
        
        
    temp1 = temp2 =0;
        for(int i=0;i<rsum.size();i++){
            temp1+= target - rsum[i];
        }
        
        for(int i=0;i<csum.size();i++){
            temp2+= target -csum[i];
        }
        
        return min(temp1 , temp2);
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends