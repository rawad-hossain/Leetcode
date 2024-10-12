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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index,
                    int start, int end) {
        if (start > end)
            return NULL;

        TreeNode* root = new TreeNode(preorder[index]);

        int split = 0;

        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[index]) {
                split = i;
                break;
            }
        }

        index++;

        root->left = build(preorder, inorder, index, start, split - 1);
        root->right = build(preorder, inorder, index, split + 1, end);

        return root;
    }
};