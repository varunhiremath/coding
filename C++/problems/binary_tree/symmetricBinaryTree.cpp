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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return isSymmetricNodes(root->left, root->right);
    }

    bool isSymmetricNodes(TreeNode *left, TreeNode *right) {

        if (!left && !right)
            return true;
        else if ((!left && right) || (left && !right))
            return false;
        else {
            if (left->val != right->val)
                return false;

            bool const rl = isSymmetricNodes(left->right, right->left);
            bool const lr = isSymmetricNodes(left->left, right->right);
            return rl && lr;
        }
    }
};
