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
        if (root == nullptr) {
            return 0;
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            int leftmost = q.front().second;
            int rightmost = leftmost;

            for (int i = 0; i < levelSize; i++) {
                auto u = q.front();
                q.pop();
                TreeNode* p = u.first;
                long  pos = u.second - leftmost; 

                if (p->left) q.push({p->left, 2 * pos + 1}); 
                if (p->right) q.push({p->right, 2 * pos + 2}); 
                rightmost = u.second;
            }

            long width = rightmost - leftmost + 1;
            maxWidth = max(maxWidth, width);
        }

        return maxWidth;
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        return helper(root);
    }
};