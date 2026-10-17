class Solution {
public:
    const int  MOD=1e9+7;
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long long>> dp(n+1,vector<long long>(amount+1,0));
        for(int i=1;i<=n;i++)dp[i][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                //take 
                long long take=(j-coins[i-1]>=0)?dp[i][j-coins[i-1]]:0;
                long long notTake=dp[i-1][j];
                dp[i][j]=take+notTake;
                if(dp[i][j]>1e12)dp[i][j]=1e12;
            }
        }
        return dp[n][amount];  
    }
};