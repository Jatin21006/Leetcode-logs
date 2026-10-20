class Solution {
public:
    int f(int k,vector<int>& prices,int index,vector<vector<int>>& dp){
        int n=prices.size();
        //n-=index;
        //base cases
        if(dp[index][k]!=-1)return dp[index][k];
        int mini=prices[index];
        int profit=0;
        for(int i=index;i<n;i++){
            mini=min(prices[i],mini);
            profit=max(profit,prices[i]-mini+f(k-1,prices,i,dp));
        }
        return dp[index][k]=profit;

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        for(int i=0;i<n;i++)dp[i][0]=0;
        for(int i=0;i<=k;i++)dp[n-1][i]=0;
        return f(k,prices,0,dp);

        
    }
};