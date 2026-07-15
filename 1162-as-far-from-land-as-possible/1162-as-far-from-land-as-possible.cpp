class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        queue<pair<pair<int,int>,int>> q;// row,col,distance;
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int d=it.second;
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n &&vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},d+1});
                    ans=d+1;
                }
            }


        }
        return (ans>0)?ans:-1;
        
    }
};