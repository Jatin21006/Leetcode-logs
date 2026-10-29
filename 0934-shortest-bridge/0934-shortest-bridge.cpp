class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int firstR=-1;
        int firstC=-1;
        int n=grid.size();
        int m=grid[0].size();
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    firstR = i;
                    firstC = j;
                    found = true;
                    break;
                }
            }

            if (found) break;
        }
        //visit first island and push the land connecting to water in queue
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        queue<vector<int>> q;
        queue<vector<int>> land;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[firstR][firstC]=1;
        land.push({firstR,firstC});
        while(!land.empty()){
            auto it=land.front();
            land.pop();
            int r=it[0];
            int c=it[1];
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(vis[nr][nc])continue;
                    vis[nr][nc]=1;
                    if(grid[nr][nc]==1){
                        land.push({nr,nc});
                    }
                    else q.push({nr,nc,0});
                    }
                    
            }

        }
        int ans=INT_MAX;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it[0];
            int c=it[1];
            int cost=it[2];
            if(grid[r][c]==1){
                ans=min(ans,cost);
            }
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(vis[nr][nc])continue;
                    vis[nr][nc]=1;
                    q.push({nr,nc,cost+1});}
            }
        }
        return ans;


        
    }
};