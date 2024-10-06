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
    void post_order(TreeNode* root, vector<int>& arr) {
        if (root == NULL)
            return;

        post_order(root->left, arr);
        post_order(root->right, arr);
        arr.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        post_order(root, arr);

        return arr;
    }
};