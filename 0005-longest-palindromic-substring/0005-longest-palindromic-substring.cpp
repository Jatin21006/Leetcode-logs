class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        //base case
        for(int i=0;i<n;i++)dp[i][i]=true;
        for(int i=0;i<n-1;i++)dp[i][i+1]=(s[i]==s[i+1]);
        //reccurrence
        for(int i=n-3;i>=0;i--){
            for(int j=i+2;j<n;j++){
                if(s[i]==s[j] && dp[i+1][j-1])dp[i][j]=true;
            }
        }
        //finding the answer;
        for(int len=n-1;len>=0;len--){
            for(int i=0;i<n-len;i++){
                int j=i+len;
                if(dp[i][j])return s.substr(i,len+1);
            }
        }
        return " ";
        
    }
};