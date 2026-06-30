class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(3,0);
        dp[1]=INT_MIN;
        dp[2]=INT_MIN;
        for(int i=0;i<n;i++){
            int rem=nums[i]%3;
            if(rem==0){
                for(int j=0;j<3;j++)dp[j]+=nums[i];
            }
            else if(rem==1){
                vector<int> new_dp(3);
                new_dp[0]=max(dp[0],dp[2]+nums[i]);
                new_dp[1]=max(dp[1],dp[0]+nums[i]);
                new_dp[2]=max(dp[2],dp[1]+nums[i]);
                dp=new_dp;
            }
            else{
                vector<int> new_dp(3);
                new_dp[0]=max(dp[0],dp[1]+nums[i]);
                new_dp[1]=max(dp[1],dp[2]+nums[i]);
                new_dp[2]=max(dp[2],dp[0]+nums[i]);
                dp=new_dp;

            }
        }
        return dp[0];
    }
};