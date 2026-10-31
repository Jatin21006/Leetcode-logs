class Solution {
public:
    const int MOD=1e9+7;
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        dp[n-1][m-1]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1)continue;
                if(grid[i][j]==0){
                    long long right=(j+1<m && grid[i][j+1]==0)?dp[i][j+1]:0;
                    long long down=(i+1<n && grid[i+1][j]==0)?dp[i+1][j]:0;
                    dp[i][j]+=right%MOD+down;
                }
                else{
                    long long valR=(j+1<m)?dp[i][j+1]:0;
                    long long valD=(i+1<n)?dp[i+1][j]:0;
                    bool r=true;
                    int nr=i;
                    int nc=j-1;
                    //down wali value bharni hai
                    while(nr>=0 && nc>=0 && grid[nr][nc]==1){
                        if(r)nr--;
                        else nc--;
                        r=!r;
                    }
                    if(nr>=0 && nc>=0)dp[nr][nc]+=valD%MOD;
                    r=false;
                    nr=i-1;
                    nc=j;
                    //right wali value bharni hai
                    while(nr>=0 && nc>=0 && grid[nr][nc]==1){
                        if(r)nr--;
                        else nc--;
                        r=!r;
                    }
                    if(nr>=0 && nc>=0)dp[nr][nc]+=valR%MOD;


                }

            }
        }
        return dp[0][0]%MOD;
        
    }
    //**BFS SOLUTION NOT WORKING DUE TO TLE**
    // int uniquePaths(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<int>> vis(n,vector<int>(m,0));
    //     long long ans=0;
    //     queue<pair<int,int>> q;//row,col
    //     int dr[]={1,0};
    //     int dc[]={0,1};
    //     q.push({0,0});
    //     vis[0][0]=1;
    //     while(!q.empty()){
    //         auto it=q.front();
    //         q.pop();
    //         int r=it.first;
    //         int c=it.second;
    //         if(r==n-1 && c==m-1){
    //             ans++;
    //             continue;
    //         }
    //         for(int i=0;i<2;i++){
    //             int nr=r+dr[i];
    //             int nc=c+dc[i];
    //             bool right=i;
    //             while(nr<n && nc<m && grid[nr][nc]==1){
    //                 if(right)nr++;
    //                 else nc++;
    //                 right=!right;
    //             }
    //             if(nr<n && nc<m)q.push({nr,nc});
    //         }
    //     }
    //     return ans%MOD;
        
    // }

    
};