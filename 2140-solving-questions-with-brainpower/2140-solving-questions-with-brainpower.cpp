class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n);
        dp[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            //solve it
            long long prev=((i+questions[i][1]+1)<n)?dp[i+questions[i][1]+1]:0;
            long long take=prev+questions[i][0];
            //skip it
            long long notTake=dp[i+1];
            dp[i]=max(take,notTake);
        }
        return dp[0];
        
    }
};