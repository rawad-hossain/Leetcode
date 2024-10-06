class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {

        vector<int> arr;
        stack<TreeNode *> st;

        if (root == NULL)
            return arr;

        while (!st.empty())
        {
            if (root != NULL)
            {
                st.push(root);
                root = root->left;
            }

            else
            {
                root = st.top();
                st.pop();
                arr.push_back(root->val);
                root = root->right;
            }
        }

        return arr;
    }
};