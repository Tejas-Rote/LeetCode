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
    vector<int> v;
    void helper( TreeNode * root){
        if( root == NULL){
            return ;
        }

        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        int ans ;
        int n  = v.size();
        ans = v[k-1];
        return ans;
    }
};