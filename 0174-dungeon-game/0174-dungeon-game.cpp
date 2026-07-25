class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int N=dungeon.size();
        int M=dungeon[0].size();
        vector<vector<int>> dp(N,vector<int>(M));
        dp[N-1][M-1]=max(1,1-dungeon[N-1][M-1]);
        for(int i=N-1;i>=0;i--){
            for(int j=M-1;j>=0;j--){
                if(i==N-1 && j==M-1)continue;
                int right=(j+1==M)?INT_MAX:dp[i][j+1];
                int down=(i+1==N)?INT_MAX:dp[i+1][j];
                dp[i][j]=max(1,min(right,down)-dungeon[i][j]);
            }
        }
        return dp[0][0];
        
    }
};