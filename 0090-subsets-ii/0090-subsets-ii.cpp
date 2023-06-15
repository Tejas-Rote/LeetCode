class Solution {
private:
    void helper(vector<vector<int>> &ans, vector<int> &nums, int index, vector<int> temp, set<int> s){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        vector<int> t = temp;
        
        // if(s.find(nums[index]) == s.end()){
        //     t.push_back(nums[index]);     
        //     s.insert(nums[index]);
        // }
        t.push_back(nums[index]);   
        
        // vector<int> t = temp;
        
        helper(ans, nums, index+1, t, s);
        helper(ans,nums,index+1, temp, s);        
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        set<int> s;
        helper(ans, nums, 0, temp, s);
        
//         for(int i=0;i<ans.size();i++){
//             for(int j=0;j<ans[i].size();j++){
//                 cout<<ans[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         cout<<endl<<"after sort"<<endl;
        
        
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(), ans[i].end());;
        }
        sort(ans.begin(),ans.end());
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
        
        
//          for(int i=0;i<ans.size();i++){
//             for(int j=0;j<ans[i].size();j++){
//                 cout<<ans[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        

//         set<vector<int>> st;
//         for(int i=0;i<ans.size();i++){
//             st.insert(ans[i]);
//         }
        
        // for (const auto& vector : st) {
        // // Access and process each vector
        //     for (const auto& element : vector) {
        //         cout << element << " ";
        //     }
        //     cout << endl;
        // }
        
//         vector<vector<int>> a;
    
//         for (const auto& vector : st) {
//             a.push_back(vector);
//         }
        
        
        return ans;
    }
};