class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<vector<int>> & graph, vector<int> &temp, int s){
        temp.push_back(s);
        if(s == graph.size()-1){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        
        for(auto x: graph[s]){
            helper(graph, temp, x);
        }
        temp.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> temp;
        helper(graph, temp, 0);
        
        return ans;
    }
}; 