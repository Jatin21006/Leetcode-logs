class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=INT_MAX;
        queue<vector<int>> q;//row,col,k_remaining,steps
        vector<vector<int>> vis(n,vector<int>(m,-1));
        vis[0][0]=k;
        //if vis[i][j]==-1 then not visited otherwise it will tell how many steps remaining at that cell
        q.push({0,0,k,0});
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it[0];
            int c=it[1];
            int k_rem=it[2];
            int steps=it[3];
            if(r==n-1 && c==m-1)return steps;
            for(int i=0;i<4;i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int a=k_rem-grid[nrow][ncol];
                    if( a>=0 && a>vis[nrow][ncol]){
                        q.push({nrow,ncol,a,steps+1});
                        vis[nrow][ncol]=a;
                    }
                }
            }

        }
        return -1;

    }
};