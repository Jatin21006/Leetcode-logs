class Solution {
public:
    int numSquares(int n) {
        int index=sqrt(n);
        vector<vector<int>> dp(index+1,vector<int>(n+1,0));
        for(int i=0;i<=n;i++)dp[1][i]=i;
        for(int i=2;i<=index;i++){
            for(int j=1;j<=n;j++){
                //pick
                int sq=i*i;
                int pick=(j-sq>=0)?dp[i][j-sq]+1:INT_MAX;
                int notPick=dp[i-1][j];
                dp[i][j]=min(pick,notPick);
            }
        }
        return dp[index][n];

        
    }
};