class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adjList(n+1);//node,distance
        for(auto it:roads){
            adjList[it[0]].push_back({it[1],it[2]});
            adjList[it[1]].push_back({it[0],it[2]});
        }
        //make vsited
        vector<int> vis(n+1,0);
        vis[0]=1;
        vis[1]=1;
        queue<pair<int,int>> q;
        q.push({1,INT_MAX});
        int ans=INT_MAX;  
        //bfs from city one
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans= min(ans,it.second);
            for(auto node:adjList[it.first]){
                if(vis[node.first])ans=min(ans,node.second);
                else{
                    q.push({node.first,node.second});
                    vis[node.first]=1;
                }
            }
        }
        return ans;   
    }
};