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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;

        recurssiveTraverse(root, 0, arr);
        return arr;
    }

    void recurssiveTraverse(TreeNode* root, int level, vector<int>& arr) {
        if (root == NULL)
            return;

        if (arr.size() == level)
            arr.push_back(root->val);

        // for right side view
        recurssiveTraverse(root->right, level + 1, arr);
        recurssiveTraverse(root->left, level + 1, arr);

        // for left side view
        /*
        recurssiveTraverse(root->left, level + 1, arr);
        recurssiveTraverse(root->right, level + 1, arr);
        */
    }
};