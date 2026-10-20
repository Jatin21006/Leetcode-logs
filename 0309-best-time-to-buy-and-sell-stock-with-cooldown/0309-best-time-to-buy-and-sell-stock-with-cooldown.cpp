class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n,0);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                //j is buy day and i is sell day
                int a=(j-2>=0)?dp[j-2]:0;
                dp[i]=max(dp[i],max(dp[i-1],prices[i]-prices[j]+a));
            }
        }
        return dp[n-1];
        
    }
};