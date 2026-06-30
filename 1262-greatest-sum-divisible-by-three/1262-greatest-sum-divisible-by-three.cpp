class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp = {0, INT_MIN, INT_MIN};

        for (int x : nums) {
            vector<int> ndp = dp;

            for (int r = 0; r < 3; r++) {
                if (dp[r] == INT_MIN) continue;
                int nr = (r + x) % 3;
                ndp[nr] = max(ndp[nr], dp[r] + x);
            }

            dp = ndp;
        }

        return dp[0];
    }
};