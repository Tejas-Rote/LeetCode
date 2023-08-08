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
    int helper(TreeNode * root){
        if(root == NULL){
            return 0;
        }
        
        int lh = helper(root->left);
        int rh = helper(root->right);
        
        if(root->left == NULL && root->right == NULL)
            return 1;
        
        if(!root->right){
            return 1 +lh;
        }
        
        if(!root->left){
            return 1 +rh;
        }
        
        return min(lh, rh)+1;
    }
    int minDepth(TreeNode* root) {
        return helper(root);
    }
};