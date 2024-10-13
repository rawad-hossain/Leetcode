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
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;

        dfs_max_path(root, maxPath);
        return maxPath;
    }

    int dfs_max_path(TreeNode* root, int& maxPath) {
        if (root == NULL)
            return 0;

        // if left or right node has neg val then set it to 0
        int left = max(0, dfs_max_path(root->left, maxPath));
        int right = max(0, dfs_max_path(root->right, maxPath));

        int currPath = root->val + left + right;

        maxPath = max(maxPath, currPath);

        return root->val + max(left, right);
    }
};