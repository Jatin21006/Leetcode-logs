class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n<=1)return 0;
        int cap=k;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(cap+1,vector<int>(2,0)));
        for(int i=1;i<=cap;i++)dp[0][i][0]=-prices[0];

        for(int i=1;i<n;i++){
            for(int j=1;j<=cap;j++){
                for(int k=0;k<2;k++){
                    if(k==0)dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][1]-prices[i]);
                    else dp[i][j][k]=max(dp[i-1][j][k],prices[i]+dp[i][j][0]);
                }
            }
        }
        return dp[n-1][cap][1];
        
    }
};