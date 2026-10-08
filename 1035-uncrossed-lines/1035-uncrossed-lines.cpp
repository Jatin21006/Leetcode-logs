class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int s=0;
                if(nums1[i-1]==nums2[j-1])s=dp[i-1][j-1]+1;
                dp[i][j]=max(s,max(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n][m];

        
    }
};