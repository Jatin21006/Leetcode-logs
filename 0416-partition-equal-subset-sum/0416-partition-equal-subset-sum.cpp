class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        //edge cases
        //if(n==1 || n==0)return 1-n;
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2)return false;
        sum=sum/2;
        //DP part
        //i  have to find evry subset sum upto i for dp[i]and if even one them matches condition then return true
        //will use take and not take algorithmn
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(nums[0]<=sum)dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                //not take
                bool notTake=dp[i-1][j];
                //take
                bool take=false;
                if(nums[i]<=j)take=dp[i-1][j-nums[i]];
                dp[i][j]=take||notTake;

            }
        }

        return dp[n-1][sum];
        
    }
};