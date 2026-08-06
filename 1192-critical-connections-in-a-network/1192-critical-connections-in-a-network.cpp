class Solution {
public:
    int timer=0;
    void dfs(vector<vector<int>>& adj,
             vector<vector<int>> &bridges,
             vector<int>& visited,int node,int parent,
             vector<int> &tin,
             vector<int> &low){


        visited[node]=1;
        low[node]=tin[node]=timer++;
        for(int i:adj[node]){
            if(i==parent)continue;
            
            if(visited[i]){
                low[node]=min(low[node],tin[i]);
            }
            else{
                dfs(adj,bridges,visited,i,node,tin,low);
                low[node]=min(low[node],low[i]);
                if(tin[node]<low[i])bridges.push_back({node,i});
            }
        }


    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> tin(n);
        vector<int> low(n);
        vector<int> visited(n,0);
        vector<vector<int>> bridges;
        dfs(adj,bridges,visited,0,-1,tin,low);
        return bridges;
        
    }
};