class Solution
{
public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }

        while (pq.size() != n - k + 1)
            pq.pop();

        return pq.top();
    }
};
