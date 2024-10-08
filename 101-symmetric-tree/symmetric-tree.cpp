/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        // If both root1 and root2 are NULL, the comparison root1 == root2
        // returns true, meaning the subtrees are symmetric.
        // If one is NULL and the other is not, the comparison root1 == root2
        // returns false, indicating the subtrees are not symmetric.
        if (left == NULL || right == NULL)
            return left == right;

        if (left->val != right->val)
            return false;

        if (isSymmetric(left->left, right->right) &&
            isSymmetric(left->right, right->left))
            return true;

        return false;

        /*
        Alternative:
        return (root1->data == root2->data)
            && isSymmetricUtil(root1->left, root2->right)
            && isSymmetricUtil(root1->right, root2->left);
        */
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) // empty tree is symmetric
            return true;

        return isSymmetric(root->left, root->right);
    }
};