
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bitset<1024>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                bitset<1024> cur;

                if (i == 0 && j == 0) {
                    cur[grid[i][j]] = 1;
                } else {
                    for (int x = 0; x < 1024; x++) {
                        bool reachable = dp[j][x];

                        if (j > 0)
                            reachable |= dp[j - 1][x];

                        if (reachable)
                            cur[x ^ grid[i][j]] = 1;
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < 1024; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return -1;
    }
};
