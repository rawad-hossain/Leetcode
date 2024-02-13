class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            if (min > prices[i])
                min = prices[i];
                
            profit = prices[i] - min;
            maxi = max(maxi, profit);
        }
        return maxi;
    }
};