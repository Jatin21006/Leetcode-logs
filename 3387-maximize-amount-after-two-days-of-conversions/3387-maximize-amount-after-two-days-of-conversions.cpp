class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string,double> mp;
        mp[initialCurrency]=1;
        queue<pair<string,double>> q;
        q.push({initialCurrency,1});
        //create adjList of both coversions;
        unordered_map<string, vector<pair<string,double>>> adj1;
        for(int i=0;i<pairs1.size();i++){
            adj1[pairs1[i][0]].push_back({pairs1[i][1],rates1[i]});
            adj1[pairs1[i][1]].push_back({pairs1[i][0],1/rates1[i]});

        }
        unordered_map<string, vector<pair<string,double>>> adj2;
        for(int i=0;i<pairs2.size();i++){
            adj2[pairs2[i][0]].push_back({pairs2[i][1],rates2[i]});
            adj2[pairs2[i][1]].push_back({pairs2[i][0],1/rates2[i]});
        }
        //max currency after day 1
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string curr=it.first;
            double amount=it.second;
            for(auto it:adj1[curr]){
                string exCurr=it.first;
                double exAmount=it.second*amount;
                if(mp.count(exCurr)){
                    if(exAmount>mp[exCurr]){
                        mp[exCurr]=exAmount;
                        q.push({exCurr,exAmount});
                    }
                }
                else{
                    mp[exCurr]=exAmount;
                    q.push({exCurr,exAmount});
                }
            }

        }
        for(auto it:mp){
            q.push(it);
        }
        //max currency after day 2
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string curr=it.first;
            double amount=it.second;
            for(auto it:adj2[curr]){
                string exCurr=it.first;
                double exAmount=it.second*amount;
                if(mp.count(exCurr)){
                    if(exAmount>mp[exCurr]){
                        mp[exCurr]=exAmount;
                        q.push({exCurr,exAmount});
                    }
                }
                else{
                    mp[exCurr]=exAmount;
                    q.push({exCurr,exAmount});
                }
            }

        }
        return mp[initialCurrency];
        
    }
};