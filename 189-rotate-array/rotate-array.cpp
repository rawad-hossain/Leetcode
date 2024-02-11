class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       // Calculate the actual number of rotations needed
    int n = nums.size();
    k = k % n;

    // Reverse the entire array
    reverse(nums.begin(),nums.begin()+n-k);

    // Reverse the first k elements
    reverse(nums.begin()+n-k,nums.end());

    // Reverse the remaining elements
    reverse(nums.begin(),nums.end());
     
    }
};