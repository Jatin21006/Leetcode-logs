class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        int ans=INT_MAX;
        vector<vector<int>> adjList(n+1);
        vector<unordered_set<int>> isConnected(n+1);

        for(auto it:edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);

            isConnected[it[1]].insert(it[0]);
            isConnected[it[0]].insert(it[1]);
        }

        set<vector<int>> trios;
        for(int i=1;i<=n;i++){
            if(adjList[i].size()<2)continue;
            for(int u=0;u<adjList[i].size()-1;u++){
                for(int v=1;v<adjList[i].size();v++){
                    //check if u and v are connected
                    int n1=adjList[i][u];
                    int n2=adjList[i][v];
                    if(isConnected[n1].count(n2)){
                        //trio found , i,n1,n2
                        //calculate degree
                        int count=adjList[i].size()+adjList[n1].size()+adjList[n2].size()-6;
                        ans=min(ans,count);
                    }
                }
            }
        }

        return (ans==INT_MAX)?-1:ans;
    }
};