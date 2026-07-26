class Solution {
public:
    void DFS(int source,vector<vector<int>> &adjList,vector<int> &visited){
        visited[source]=1;
        for(int node:adjList[source]){
            if(!visited[node])DFS(node,adjList,visited);
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
                DFS(i,adjList,visited);
                count++;
            }
        }
        return count;

        
    }
};