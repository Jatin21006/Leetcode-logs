class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int roomVis=1;
        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);
        vis[0]=1;
        while(!q.empty()){
            int room=q.front();
            q.pop();
            for(auto it:rooms[room]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                    roomVis++;
                }
            }
        }
        return (roomVis==n)?true:false;
        
    }
};