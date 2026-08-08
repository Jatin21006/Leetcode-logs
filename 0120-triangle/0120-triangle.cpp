class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp;
        int n=triangle.size();
        dp.push_back(triangle[0][0]);
        int sz=2;
        for(int i=1;i<triangle.size();i++){
            vector<int> temp(sz);
            for(int j=0;j<sz;j++){
                //j exist na kare toh j-1
                if(j==sz-1)temp[j]=triangle[i][j]+dp[j-1];
                //agar j-1 na kare toh j
                else if (j==0)temp[j]=triangle[i][j]+dp[j];
                //agar dono kare toh
                else temp[j]=triangle[i][j]+min(dp[j],dp[j-1]);
            }
            dp=temp;
            sz++;
        }
        int ans=INT_MAX;
        for(int i=0;i<sz-1;i++)ans=min(ans,dp[i]);
        return ans;
    }
};