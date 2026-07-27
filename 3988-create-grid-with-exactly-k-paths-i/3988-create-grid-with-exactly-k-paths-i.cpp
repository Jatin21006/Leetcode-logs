class Solution {
public:
    int paths(vector<string> &Grid,int m, int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                int up=(i-1>=0)?dp[i-1][j]:0;
                int left=(j-1>=0)?dp[i][j-1]:0;
                if(Grid[i][j]=='.')dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];

    }
    vector<string> createGrid(int m, int n, int k) {
        vector<string> Grid(m,string(n,'.'));
        if(paths(Grid,m,n)==k)return Grid;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0 )continue;
                if(i==m-1 && j==n-1)continue;
                Grid[i][j]='#';
                if(paths(Grid,m,n)<k)Grid[i][j]='.';
                else if(paths(Grid,m,n)==k)return Grid;
            }
        }
        return {};

        
    }
};