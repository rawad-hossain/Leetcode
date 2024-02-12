class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n = a.size(), count;
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (a[i] == a[j])
                    count++;
                if (count > n / 2)
                    return a[i];
            }
        }
        return -1;
    }
};