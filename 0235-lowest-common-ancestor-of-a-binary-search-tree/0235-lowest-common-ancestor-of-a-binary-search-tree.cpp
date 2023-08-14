/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode * lca(TreeNode * root, TreeNode * p, TreeNode* q){
        if(root == p || root == q || root == NULL){
            return root;
        }
        
        TreeNode * l = lca(root->left, p , q);
        TreeNode* r = lca(root->right, p , q);
        
        if(l == NULL){
            return r;
        }else if(r == NULL){
            return l;
        }else {
            return root;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root ,p ,q);
    }
};