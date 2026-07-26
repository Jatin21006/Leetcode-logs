class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n);
        for(int i=0;i<n;i++){
            if(i!=headID)adjList[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                int node=q.front().first;
                int time=q.front().second;
                ans=max(ans,time);
                q.pop();
                for(auto it:adjList[node]){
                    q.push({it,time+informTime[node]});
                }
            }
        }
        return ans;
        
    }
};