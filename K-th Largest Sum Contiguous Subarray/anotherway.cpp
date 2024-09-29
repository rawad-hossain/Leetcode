#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int KthLargest_SubArray(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];

                if (pq.size() < k)
                {
                    pq.push(sum);
                }
                else if (sum > pq.top())
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }

        return pq.top();
    }
};   