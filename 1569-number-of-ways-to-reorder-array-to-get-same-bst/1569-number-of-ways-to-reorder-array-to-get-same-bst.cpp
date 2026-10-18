class Solution {
public:
// to find combinations
    vector<vector<long long>> pascal;
    const int MOD=1e9+7;
    void buildPascal(int n) {
        pascal.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; ++i) {
            pascal[i][0] = 1;
            pascal[i][i] = 1;

            for (int j = 1; j < i; ++j) {
                pascal[i][j] =
                    (pascal[i - 1][j - 1] +
                    pascal[i - 1][j]) % MOD;
            }
        }
    }
    int ways(vector<int> & nums){
        int n=nums.size();
        if(nums.size()<=2)return 1;
        int root=nums[0];
        vector<int> left;
        vector<int> right;
        for(int i=1;i<n;i++){
            if(nums[i]<root)left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        int L=left.size();
        int R=right.size();
        long long ans = pascal[L + R][L];
        ans = ans * ways(left) % MOD;
        ans = ans * ways(right) % MOD;
        return ans;

    }
    int numOfWays(vector<int>& nums) {
        buildPascal(nums.size());
        return ways(nums)-1;
        
    }
};