/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *inorderPredecessor(TreeNode *root, TreeNode *target)
    {
        TreeNode *Predecessor = NULL;

        while (root != NULL)
        {
            if (target->val < root->val)
                root = root->left;

            else
            {
                Predecessor = root;
                root = root->right;
            }
        }

        return Predecessor;
    }
};