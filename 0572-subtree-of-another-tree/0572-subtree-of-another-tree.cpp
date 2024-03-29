class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        
        if (root == nullptr) {
            return false;
        }

      
        if (isIdentical(root, subRoot)) {
            return true;
        }


        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isIdentical(TreeNode* node1, TreeNode* node2) {


        if (node1 == nullptr || node2 == nullptr) {
            return node1 == nullptr && node2 == nullptr;
        }


        return node1->val == node2->val && 
            isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right);
    }
};