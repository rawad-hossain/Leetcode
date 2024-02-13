class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, minPrice = INT_MAX, maxPrice = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            profit = prices[i] - minPrice;
            maxPrice = max(maxPrice, profit);
        }
        return maxPrice;
    }
};