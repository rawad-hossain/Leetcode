#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int kthLargestSum(vector<int> &nums, int k)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                ans.push_back(sum);
            }
        }

        sort(ans.begin(), ans.end(), greater<int>());

        return ans[k - 1];
    }
};