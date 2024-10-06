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
vector<int> preorderTraversal(TreeNode *root)
{
    // {   1 (root) -> 2 (left) ->3 (right)
    // output = 1, 2, 3
    /*stack
     |2
     |3
     |1
     */
    vector<int> arr;
    stack<TreeNode *> st;

    if (root == NULL)
        return;

    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();

        arr.push_back(root->val); // 1 already inseted

        // left node to be printed first so have to keep it at top
        if (root->right != NULL) // lastly insert 2
            st.push(root->right);

        if (root->left != NULL)
            st.push(root->left); // secondly, insert 3
    }

    return arr;
}