class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int index = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0)
                arr[index++] =
                    arr[i]; // overwriting first few elemets with non zero value
        }

        for (int i = index; i < n; i++) // refilling empty slots with zero
            arr[i] = 0;
    }
};