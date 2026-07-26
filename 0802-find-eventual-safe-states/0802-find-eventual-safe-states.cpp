class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        queue<int> q;
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
            }
            indegree[i]=graph[i].size();
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)ans.push_back(i);
        }
        return ans;
    }
};