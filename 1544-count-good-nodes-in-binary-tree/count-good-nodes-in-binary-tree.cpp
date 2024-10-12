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
    int goodNodes(TreeNode* root) {
        int goodCount = 0;
        dfs(root, root->val, goodCount);
        return goodCount;
    }

    void dfs(TreeNode* root, int maxSoFar, int& goodCount) {
        if (root == NULL)
            return;

        if (root->val >= maxSoFar)
            goodCount++;

        maxSoFar = max(maxSoFar, root->val);

        dfs(root->left, maxSoFar, goodCount);
        dfs(root->right, maxSoFar, goodCount);
    }
};