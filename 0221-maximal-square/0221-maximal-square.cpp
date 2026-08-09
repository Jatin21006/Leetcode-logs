class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() ||matrix[0].empty())return 0;
        int maxSide=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int up=dp[i-1][j];
                int left=dp[i][j-1];
                int diagnol=dp[i-1][j-1];
                if(matrix[i-1][j-1]=='0')dp[i][j]=0;
                else dp[i][j]=min(up,min(left,diagnol))+1;
                maxSide=max(maxSide,dp[i][j]);
            }
        }
        return maxSide*maxSide;
        
    }
};