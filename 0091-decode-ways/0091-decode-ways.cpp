class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        if(s[0]!='0')dp[1]=1;
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0')dp[i]+=dp[i-1];
            if(s[i-2]!='0'){
                int sum=0;
                sum+=10*(s[i-2]-'0');
                sum+=s[i-1]-'0';
                if(sum<27){dp[i]+=dp[i-2];}}
        }
        return dp[n];
        
    }
};