class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(2,vector<int>(n,1));//take - not take
        dp[1][0]=0;
        for(int i=1;i<n;i++){
            //dp[0]- take
            for(int j=i;j>=0;j--){
                if(nums[j]<nums[i])dp[0][i]=max(dp[0][j]+1,dp[0][i]);
            }
            //dp[1]- not take
            dp[1][i]=max(dp[0][i-1],dp[1][i-1]);

        }
        return max(dp[0][n-1],dp[1][n-1]);
    }
};