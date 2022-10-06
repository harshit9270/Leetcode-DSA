class Solution {
public:
    // Optimal TC-> O(n) SC-> O(1)
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPrice = INT_MAX;

        for (int i = 0; i < prices.size(); i++) {
            maxPro = max(maxPro, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        return maxPro;
    }
};