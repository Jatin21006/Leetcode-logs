class Solution {
public:
    int isSubstring(string s,string word){
        int n=s.size();
        int m=word.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //match
                if(s[i-1]==word[j-1])dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]==n)return true;
            }
        }
        return false;

    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(int i=0;i<patterns.size();i++){
            if(isSubstring(patterns[i],word))ans++;
        }
        return ans;
    }
};