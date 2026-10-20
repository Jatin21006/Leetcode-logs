class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
        for(int i=0;i<n-1;i++){
            int profit=prices[i+1]-prices[i];
            ans+=max(0,profit);
        }
        return ans;
    }
};