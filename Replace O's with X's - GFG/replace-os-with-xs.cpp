//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void f(int i,int j,vector<vector<char>>&m){
        if(i<0 || j<0 || i>=m.size() || j>=m[0].size() || m[i][j]=='X'||m[i][j]=='x'){
            return ;
        }
        m[i][j]='x';
        f(i+1,j,m);
        f(i-1,j,m);
        f(i,j+1,m);
        f(i,j-1,m);
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> g)
    {
        // code here
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || !j || i==n-1 ||j==m-1)
                if(g[i][j]=='O'){
                    f(i,j,g);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]!='x'){
                    g[i][j]='X';
                }
                else{
                    g[i][j]='O';
                }
            }
        }
        return g;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends