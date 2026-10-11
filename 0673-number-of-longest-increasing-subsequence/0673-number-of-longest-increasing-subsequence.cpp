class Solution {
public:
    vector<int> LIS(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])dp[i]=max(dp[i],dp[j]+1);
            }
        }
        return dp;
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp=LIS(nums);
        vector<int> ways(n,1);

        for(int i=1;i<n;i++){
            if(dp[i] > 1){
                ways[i] = 0;

                for(int j=0;j<i;j++){
                    if(nums[j] < nums[i] && dp[j]+1 == dp[i]){
                        ways[i] += ways[j];
                    }
                }
            }
        }
        int ans=0;
        int maxi=*max_element(dp.begin(),dp.end());
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                 ans+=ways[i];
            }
        }
        return ans;
        
    }
};