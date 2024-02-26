//run time error, exceeds time complexity

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &arr)
    {
        int n = arr.size();
        set<vector<int>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; j < n; k++)
                {
                    if (arr[i] + arr[j] + arr[k] == 0)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
