/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> v;
    void helper(TreeNode * root){
        if (!root) return;
        
        queue<TreeNode*> q;
        // vector<vector<int>> out;
            
        q.push(root);  
        int level = 0; /* to alternate levels, or a bool variable */
        
        while (!q.empty()) {
            
            int sz = q.size();  
            vector<int> curr(sz); 
            
            for (int i = 0; i < sz; i++) {
                
                TreeNode* tmp = q.front();
                q.pop();
                
                if (level == 0) {
                    curr[i] = tmp->val;
                } else {
                    curr[sz - i - 1] = tmp->val; 
                }
                
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            v.push_back(curr);
            level = !level; 
        }
        // return out;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // vector<vector<int>>v ;
        helper(root);
        return v;
    }
};