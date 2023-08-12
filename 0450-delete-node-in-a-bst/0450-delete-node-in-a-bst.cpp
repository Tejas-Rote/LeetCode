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
    TreeNode * findLastRightChild(TreeNode * root){
        if(root->right == NULL){
            return root;
        }
        return findLastRightChild(root->right);
    }
    TreeNode * helper(TreeNode * root){
        if(root->left == NULL){
            return root->right;
        }
        TreeNode* rightChild = root->right;
        TreeNode * lastRightChild = findLastRightChild(root->left);
        lastRightChild ->right = rightChild;
        
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        
        if(root->val ==key){
            return helper(root);
        }
        
        TreeNode * dum = root;
        while(root != NULL){
            if(root->val> key){
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                }else {
                    root = root->left;
                }
            }else {
                if(root->right != NULL && root->right->val == key){
                    root ->right = helper(root->right);
                }
                else{
                    root = root->right;
                }
            }
        }
        return dum;
    }
};