class Solution {
private:
    void helper(vector<vector<int>> &ans , vector<int> &candidates, int target , vector<int> &s, int index){
        
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(s);
            }
            return;
        }
        
            
        
        if(target>=candidates[index]){
            s.push_back(candidates[index]);
            // still on the same index as it can repeat
            helper(ans, candidates, target-candidates[index], s, index);
            s.pop_back();
        }
        helper(ans, candidates, target, s , index+1);
        
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> s;
        
        helper(ans, candidates, target, s, 0);
        
        
        return ans;
    }
};