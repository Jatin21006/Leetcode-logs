class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                //take
                int take=(j-coins[i]>=0 && dp[i][j-coins[i]]!=-1)?1+dp[i][j-coins[i]]:INT_MAX;
                //not take
                int notTake=(i-1>=0 && dp[i-1][j]!=-1)?dp[i-1][j]:INT_MAX;
                dp[i][j]=(take==INT_MAX && notTake==INT_MAX)?-1:min(take,notTake);
            }
        }
        return dp[n-1][amount];
        
    }
};