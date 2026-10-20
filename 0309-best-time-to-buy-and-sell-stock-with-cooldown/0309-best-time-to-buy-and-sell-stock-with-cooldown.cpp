class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        vector<int> dp(n, 0), buy(n, 0);
        buy[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            int prev2 = (i >= 2) ? dp[i-2] : 0;
            buy[i] = max(buy[i-1], prev2 - prices[i]);
            dp[i]  = max(dp[i-1], buy[i-1] + prices[i]);
        }
        return dp[n-1];
    }
};