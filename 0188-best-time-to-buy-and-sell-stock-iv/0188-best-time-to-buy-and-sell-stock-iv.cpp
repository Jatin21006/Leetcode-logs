class Solution {
public:
    // int f(int k,vector<int>& prices,int index,vector<vector<int>>& dp){
    //     int n=prices.size();
    //     //n-=index;
    //     //base cases
    //     if(dp[index][k]!=-1)return dp[index][k];
    //     int mini=prices[index];
    //     int profit=0;
    //     for(int i=index;i<n;i++){
    //         mini=min(prices[i],mini);
    //         profit=max(profit,prices[i]-mini+f(k-1,prices,i,dp));
    //     }
    //     return dp[index][k]=profit;

    // }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k<=0 || n<2)return 0;
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        // Stage 2: Inner loop eliminated! — O(N * K)
        for (int t = 1; t <= k; t++) {
            // Before starting index = n - 2, the only future sell day is i = n - 1:
            int bestSell = prices[n - 1] + dp[n - 1][t - 1];

            for (int index = n - 2; index >= 0; index--) {
                // Include i = index as a possible sell day
                bestSell = max(bestSell, prices[index] + dp[index][t - 1]);

                // Option 1: Don't buy at index -> dp[index + 1][t]
                // Option 2: Buy at index       -> -prices[index] + bestSell
                dp[index][t] = max(dp[index + 1][t], -prices[index] + bestSell);
            }
        }
        return dp[0][k];
    }
};