class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        unordered_set<int> s(days.begin(),days.end());
        vector<int> dp(366,0);
        //dp[days[0]]=min(min(costs[0],costs[1]),costs[2]);
        for(int i=days[0];i<=365;i++){
            if(!s.count(i))dp[i]=dp[i-1];
            else{
                //take costs[0] ticket
                int a=dp[i-1]+costs[0];
                //take costs[1] ticket
                int b=(i-7>=0)?dp[i-7]+costs[1]:costs[1];
                //take costs[2] ticket
                int c=(i-30>=0)?dp[i-30]+costs[2]:costs[2];
                dp[i]=min(min(a,b),c);
            }
        }
        return dp[365];
    }
};