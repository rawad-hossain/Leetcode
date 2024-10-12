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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1; // Start from the last element in postorder (the root)
        return build(postorder, inorder, index, 0, inorder.size() - 1);
    }

private:
    // Recursive function to build the tree
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int& index, int start, int end) {
        if (start > end) {  // Base case: if the range is invalid, return NULL
            return NULL;
        }

        // Step 1: The last element in postorder is the root node
        TreeNode* root = new TreeNode(postorder[index]);

        // Step 2: Find the root's position in the inorder array
        int split = 0;
        for (int k = 0; k < inorder.size(); k++) {
            if (postorder[index] == inorder[k]) {
                split = k;
                break;
            }
        }

        // Step 3: Decrement the index for the next recursive call
        index--;

        // Step 4: Recursively build the right and left subtrees
        // Build the right subtree first, because we are moving from the end of the postorder array
        root->right = build(postorder, inorder, index, split + 1, end);
        // Then build the left subtree
        root->left = build(postorder, inorder, index, start, split - 1);

        // Return the constructed tree
        return root;
    }
};
