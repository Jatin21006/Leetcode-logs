class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int left=(j==0)?INT_MAX:dp[j-1];
                int right=(j==n-1)?INT_MAX:dp[j+1];

                temp[j]=matrix[i][j]+min(dp[j],min(left,right));
            }
            dp=temp;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[i]);
        }
        return ans;
        
    }
};