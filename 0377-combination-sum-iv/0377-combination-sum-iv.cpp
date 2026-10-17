class Solution {
public:
    int ways(vector<int>& nums,int index,int target,vector<vector<int>>& dp){
        if(target==0)return 1;
        if(target<0 ||index==nums.size())return 0;
        if(dp[index][target]!=-1)return dp[index][target];
        int take=ways(nums,0,target-nums[index],dp);
        int notTake=ways(nums,index+1,target,dp);
        return dp[index][target]=take+notTake;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return ways(nums,0,target,dp);
        
    }
};