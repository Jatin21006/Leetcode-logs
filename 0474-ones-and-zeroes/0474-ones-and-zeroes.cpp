class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s=strs.size();
        vector<int> zeroCnt(s);
        vector<int> oneCnt(s);
        for(int i=0;i<s;i++){
            for(char c:strs[i]){
                if(c=='0')zeroCnt[i]++;
                else oneCnt[i]++;
            }
        }
        vector<vector<vector<int>>> dp(s+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i=1;i<=s;i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    //take
                    int take=(j-zeroCnt[i-1]>=0 && k-oneCnt[i-1]>=0)?dp[i-1][j-zeroCnt[i-1]][k-oneCnt[i-1]]+1:0;
                    //notTake
                    int notTake=dp[i-1][j][k];
                    dp[i][j][k]=max(take,notTake);
                }
            }
        }
        return dp[s][m][n];

    }
};