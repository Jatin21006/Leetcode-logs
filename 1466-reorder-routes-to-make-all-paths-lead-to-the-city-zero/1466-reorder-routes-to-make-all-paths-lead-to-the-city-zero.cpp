class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans=0;
        vector<vector<int>> adj(n);
        vector<vector<int>> inNodes(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            inNodes[it[1]].push_back(it[0]);
        }
        vector<int> reach(n,0);
        reach[0]=1;
        //mark every that can reach 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int it:inNodes[node]){
                if(reach[it]==0){
                    q.push(it);
                    reach[it]=1;
                }
            }
        }
        //nodes that can reach 0
        for(int i=0;i<n;i++){
            if(reach[i]==1)q.push(i);
        }
        //take outgoing edges from these nodes and turn them and add their outgoing edges
        //and mark their incoming edge
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(reach[it]==0){
                    reach[it]=1;
                    ans++;
                    q.push(it);
                }
            }
            for(auto it:inNodes[node]){
                if(reach[it]==0){
                    reach[it]=1;
                    q.push(it);
                }
            }
        }
        
        
        return ans;

        
    }
};