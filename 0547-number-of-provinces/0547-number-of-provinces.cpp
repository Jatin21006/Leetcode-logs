class Solution {
public:
    void BFS(int source,vector<vector<int>> &adjList,vector<int> &visited){
        visited[source]=1;
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            for(auto edge:adjList[it]){
                if(visited[edge]==0){
                    visited[edge]=1;
                    q.push(edge);
                }
            }

        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<vector<int>> adjList(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++ ){
                if(isConnected[i][j]==1)adjList[i].push_back(j);
            }
        }
        int count=0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                BFS(i,adjList,visited);
                count++;
            }
        }
        return count;

        
    }
};