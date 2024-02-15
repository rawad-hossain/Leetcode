class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return 0;
        sort(arr.begin(), arr.end());
        int count = 0, lastSmaller = INT_MIN, length = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] - 1 == lastSmaller) {
                count++;
                lastSmaller = arr[i];
            } else if (arr[i] != lastSmaller) {
                count = 1; // new sequence
                lastSmaller = arr[i];
            }
            length = max(length, count);
        }
        return length;
    }
};