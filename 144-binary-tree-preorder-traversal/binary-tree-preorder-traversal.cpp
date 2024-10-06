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
class Solution
{
public:
    void pre_order(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;

        arr.push_back(root->val);

        pre_order(root->left, arr);
        pre_order(root->right, arr);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> arr;
        pre_order(root, arr);

        return arr;
    }
};