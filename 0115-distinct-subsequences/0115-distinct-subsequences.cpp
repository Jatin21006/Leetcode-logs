class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<double> dp(n+1,1);
        vector<double> prev(n+1,1);
        dp[0]=0;
        
        for(int j=1;j<=m;j++){
            for(int i=1;i<=n;i++){
                if(s[i-1]==t[j-1]){
                    dp[i]=prev[i-1]+dp[i-1];
                }
                else dp[i]=dp[i-1];
            }
            prev=dp;
        }
        return (int)dp[n];
    }
};