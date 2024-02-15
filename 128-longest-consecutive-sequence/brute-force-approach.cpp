class Solution {
public:
    bool linearSearch(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == k)
                return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if (n == 0)
            return 0;

        int length = 1, x;
        for (int i = 0; i < n; i++) {
            x = arr[i];
            int count = 1;
            while (linearSearch(arr, x + 1) == true) {
                x++;
                count++;
            }
            length = max(length, count);
        }
        return length;
    }
};
