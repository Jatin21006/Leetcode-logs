class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const auto& a,const auto& b){
            if(a[1]!=b[1])return a[1]<b[1];
            return a[0]<b[0];
        });
        int n=pairs.size();
        int ans=0;
        int lastEnd=INT_MIN;
        for(int i=0;i<n;i++){
            if(pairs[i][0]>lastEnd){
                ans++;
                lastEnd=pairs[i][1];
            }
        }

        return ans;

    }
};