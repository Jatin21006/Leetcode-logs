class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n=bank.size();
        unordered_set<string> s(bank.begin(),bank.end());
        if(!s.count(endGene))return -1;
        unordered_set<string> visited;
        queue<pair<string,int>> q;
        q.push({startGene,0});
        char v[]={'A','C','G','T'};
        while(!q.empty()){
            auto it=q.front();
            string curr=it.first;
            int count=it.second;
            q.pop();
            if(curr==endGene)return count;
            for(int i=0;i<8;i++){
                char org=curr[i];
                for(int j=0;j<4;j++){
                    curr[i]=v[j];
                    if(s.count(curr) && !visited.count(curr)){
                        q.push({curr,count+1});
                        visited.insert(curr);
                    }
                }
                curr[i]=org;
                
            }
        }
        return -1;
    }
};