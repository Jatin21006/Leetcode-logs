class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        if(n==0)return 0;
        int sum=accumulate(stones.begin(),stones.end(),0);
        int mini=INT_MAX;
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(stones[0]<=sum)dp[0][stones[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake=dp[i-1][j];
                bool take=false;
                if(stones[i]<=j)take=dp[i-1][j-stones[i]];
                dp[i][j]=take||notTake;
                if(dp[i][j]){
                    int ans=abs(sum-2*j);
                    mini=min(mini,ans);
                }
            }
        }
        return (mini==INT_MAX)?stones[0]:mini;
        
    }
};