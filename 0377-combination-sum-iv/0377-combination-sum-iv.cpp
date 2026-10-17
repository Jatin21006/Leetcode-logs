
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<long long>> dp(n+1,vector<long long>(target+1,0));

        // Base case: target == 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Bottom-up calculation
        for (int t = 1; t <= target; t++) {
            for (int i = n - 1; i >= 0; i--) {
                int take = 0;

                if (t >= nums[i]) {
                    take = dp[0][t - nums[i]];
                }

                int notTake = dp[i + 1][t];

                dp[i][t] = 1LL*take + notTake;
                if(dp[i][t]>1e12)dp[i][t]=1e12;
            }
        }

        return dp[0][target];
    }
};
