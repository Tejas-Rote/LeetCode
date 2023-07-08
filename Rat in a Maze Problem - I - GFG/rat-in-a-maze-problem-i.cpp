//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    
    void dfs(int i, int j, vector<vector<int>> m, vector<vector<int>> &vis, string path, int n,
    vector<string> &ans) {
        if(i < 0 || i>=n || j< 0 || j>=n) return;
        
        if(m[i][j] == 0 || vis[i][j] == 1) return;
        
        if(i == n-1 && j == n-1 && m[i][j] != 0) {
            ans.push_back(path);
            return;
        }
        
        vis[i][j] = 1;
        
        dfs(i+1, j, m, vis, path + 'D', n, ans);
        dfs(i, j+1, m, vis, path + 'R', n, ans);
        dfs(i-1, j, m, vis, path + 'U', n, ans);
        dfs(i, j-1, m, vis, path + 'L', n, ans);
        
        vis[i][j] = 0;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n, 0));
        
        dfs(0, 0, m, vis,"", n, ans);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends