class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> ans;
        queue<vector<int>> q;
        q.push({0});
        while(!q.empty()){
            auto v=q.front();
            q.pop();
            int node=v.back();
            if(node==n-1)ans.push_back(v);
            else{
                for(auto it:graph[node]){
                    v.push_back(it);
                    q.push(v);
                    v.pop_back();
                }

            }
        }
        return ans;
        
    }
};