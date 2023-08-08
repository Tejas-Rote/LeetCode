class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(vector<int> & a, int n , int k, int idx,vector<int> & temp){
        if(temp.size()== k){
            ans.push_back(temp);
            return ;
        }
        for(int i = idx;i<n;i++){
            temp.push_back(a[i]);
            helper(a, n, k, i+1, temp );
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> a;
        for(int i=0;i<n;i++){
            a.push_back(i+1);
        }
        vector<int> temp;
        helper(a, n, k, 0, temp);
        return ans;
    }
};