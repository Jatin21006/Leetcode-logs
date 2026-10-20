class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)return 0;
        vector<int> profit1(n,0);
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--){
            maxi=max(maxi,prices[i]);
            int p=maxi-prices[i];
            profit1[i]=max(p,profit1[i+1]);
        }
        int mini=prices[0];
        vector<int> profit2(n,0);
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            mini=min(mini,prices[i]);
            int p=prices[i]-mini;
            profit2[i]=max(p,profit2[i-1]);
            ans=max(ans,profit1[i]+profit2[i]);
        }
        return ans;
        
    }
};