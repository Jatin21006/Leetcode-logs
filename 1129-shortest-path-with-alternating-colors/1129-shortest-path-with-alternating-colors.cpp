class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> ans(n,vector<int>(2,-1));
        ans[0][0]=0;
        ans[0][1]=0;
        vector<vector<int>> adjRed(n);
        for(auto it:redEdges){
            adjRed[it[0]].push_back(it[1]);
        }
        vector<vector<int>> adjBlue(n);
        for(auto it:blueEdges){
            adjBlue[it[0]].push_back(it[1]);
        }
        queue<vector<int>> q;//node,distance,color//red=0,blue=1,blank=-1
        q.push({0,0,0});
        q.push({0,0,1});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it[0];
            int d=it[1];
            int color=it[2];
            if(color==0 ){
                for(int neigh:adjBlue[node]){
                    if(ans[neigh][1]==-1 || ans[neigh][1]>d+1){
                        ans[neigh][1]=d+1;
                        q.push({neigh,d+1,1});
                    }
                }

            }
            if(color==1 ){
                for(int neigh:adjRed[node]){
                    if(ans[neigh][0]==-1 || ans[neigh][0]>d+1){
                        ans[neigh][0]=d+1;
                        q.push({neigh,d+1,0});
                    }
                }

            }

        }
        vector<int> dist(n,-1);
        for(int i = 0; i < n; i++){
            if(ans[i][0] != -1 && ans[i][1] != -1) {
                dist[i] = min(ans[i][0], ans[i][1]);
            } else if (ans[i][0] != -1) {
                dist[i] = ans[i][0];
            } else if (ans[i][1] != -1) {
                dist[i] = ans[i][1];
            }
        }
        return dist;
        
    }
};