class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sorting 
        sort(envelopes.begin(),envelopes.end(),[](const auto& a, const auto& b){
            if(a[0]==b[0])return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=envelopes.size();
        vector<int> width(n);
        for(int i=0;i<n;i++)width[i]=envelopes[i][1];
        //LIS
        vector<int> tails;
        tails.push_back(width[0]);
        for(int i=1;i<n;i++){
            auto x=lower_bound(tails.begin(),tails.end(),width[i]);
            if(x==tails.end())tails.push_back(width[i]);
            else *x=width[i];

        }
        return tails.size();
    }
};