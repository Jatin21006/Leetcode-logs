class Solution {
public:
    int f(int i,int j,vector<int>& cuts,int n,int last,
          vector<vector<int>> &dp){
        //base case
        if(i==j)return 0;
        if(dp[i][j-1]!=-1)return dp[i][j-1];
        int mini=1e9;
        for(int k=i;k<j;k++){
            int y=last-cuts[k];
            int x=n-y;
            int cost=n+f(i,k,cuts,x,cuts[k],dp)+f(k+1,j,cuts,y,last,dp);
            mini=min(mini,cost);
        }
        return dp[i][j-1]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int m=cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        sort(cuts.begin(),cuts.end());
        return f(0,m,cuts,n,n,dp);
        
    }
};