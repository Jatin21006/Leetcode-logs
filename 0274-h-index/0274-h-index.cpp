class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int ans=1;
        sort(citations.begin(),citations.end());
        if(citations[n-1]==0)return 0;
        for(int i=0;i<n;i++){
            if(citations[i]==0)continue;
            if((n-i)>=citations[i])ans=max(ans,citations[i]);
            else ans=max(ans,n-i);
        }
        return ans;
    }
};