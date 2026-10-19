class Solution {
public:
    const int MOD=1e9+7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1,0);
        dp[0]=1;
        for(int i=1;i<=high;i++){
            //place zero '0'
            long long a=(i-zero>=0)?dp[i-zero]:0;
            //place one '1'
            long long b=(i-one>=0)?dp[i-one]:0;
            dp[i]=(1LL*a+b)%MOD;
        }
        int ans=0;
        for(int i=low;i<=high;i++){
            ans=(ans+1LL*dp[i])%MOD;
        }
        return ans%MOD;

        
    }
};