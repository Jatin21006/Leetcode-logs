class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> freq;
        vector<int> dis;
        for(auto it:nums){
            if(!freq.count(it)){
                dis.push_back(it);
            }
            freq[it]++;
        }
        sort(dis.begin(),dis.end());
        int prev=0;
        int ans=dis[0]*freq[dis[0]];
        for(int i=1;i<dis.size();i++){
            int temp=ans;
            if(dis[i-1]+1<dis[i])prev=ans;
            ans=max(ans,dis[i]*freq[dis[i]]+prev);
            prev=temp;
        }
        return ans;
    }
};