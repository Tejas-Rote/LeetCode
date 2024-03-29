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
vector<int> ans;
    void printf(TreeNode * root){
        if (root == NULL)
            return;
    
        queue<TreeNode*> q;
        q.push(root);
    
        while (!q.empty()) {

            int n = q.size();

            while (n--) {
    
                TreeNode* x = q.front();
                q.pop();

                if (n == 0) {
                    cout << x->val << " ";
                    ans.push_back(x->val);
                }

                if (x->left)
                    q.push(x->left);

                if (x->right)
                    q.push(x->right);
            }
        }
    }
    
    void helper(TreeNode * root, int level , vector<int> &ans){
        if(root==NULL){
            return ;
        }
        if(ans.size() == level) ans.push_back(root->val);
        
        helper(root->right, level+1, ans);
        helper(root->left, level+1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        // printf(root);
        vector<int> ans;
        helper(root, 0, ans);
        return ans;
    }
};