class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> freq(n+1,0);//no of citations,count
        for(auto it:citations){
            if(it>=n)freq[n]++;
            else freq[it]++;
        }
        if(freq[n]>=n)return n;
        for(int i=n-1;i>=0;i--){
            freq[i]+=freq[i+1];
            if(freq[i]>=i)return i;
        }
        return 0;
    }
};