class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
            sum += arr[i];

        int total_sum = n * (n + 1) / 2;

        return total_sum - sum;
    }
};