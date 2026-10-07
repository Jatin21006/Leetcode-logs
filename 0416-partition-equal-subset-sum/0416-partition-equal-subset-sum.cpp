class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int target=accumulate(nums.begin(),nums.end(),0);
        if(target%2)return false;
        target=target/2;
        vector<vector<bool>> dp(n+1,vector<bool>(target+1));
        //base case
        for(int i=0;i<=n;i++)dp[i][0]=true;
        for(int i=1;i<=target;i++)dp[0][i]=false;
        //reccuenvce
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                bool take=false;
                if(j-nums[i-1]>=0)take=dp[i-1][j-nums[i-1]];
                bool notTake=dp[i-1][j];
                dp[i][j]=take||notTake;
            }
        }
        return dp[n][target];


        
    }
};