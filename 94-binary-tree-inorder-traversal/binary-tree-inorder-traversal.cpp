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
    void in_order(TreeNode* root, vector<int>& arr) {
        if (root == NULL)
            return;

        in_order(root->left, arr);
        arr.push_back(root->val);
        in_order(root->right, arr);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        in_order(root, arr);

        return arr;
    }
};