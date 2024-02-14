class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> output(n);
        int pos = 0, neg = 1; // indexing pos to even, neg to odd

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                output[pos] = arr[i];
                pos += 2;
            }

            else {
                output[neg] = arr[i];
                neg += 2;
            }
        }
        return output;
    }
};