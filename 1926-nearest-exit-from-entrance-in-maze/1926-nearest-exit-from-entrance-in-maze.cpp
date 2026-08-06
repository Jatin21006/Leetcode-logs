class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[entrance[0]][entrance[1]]=1;
        queue<vector<int>> q;//row col and steps
        q.push({entrance[0],entrance[1],0});
        int drow[]={1,0,-1,0};
        int dcol[]={0,-1,0,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it[0];
            int col=it[1];
            int steps=it[2];
            if(steps!=0){//cannot exit from entrace
                if(row==0 || col==0 ||row==n-1 || col==m-1)return steps;//exit found
            }
           
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                   maze[nrow][ncol]=='.' && visited[nrow][ncol]==0){
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol,steps+1});
                }
            }
        }
        return -1;
        
    }
};