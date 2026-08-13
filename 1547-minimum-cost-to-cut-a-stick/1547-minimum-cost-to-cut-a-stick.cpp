class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m,0));
        //base case
        for(int i=0;i<m;i++)dp[i][i]=0;

        for(int i=m-1;i>=0;i--){
            for(int j=i+2;j<m;j++){
                int mini=1e9;
                for(int k=i+1;k<j;k++){
                    int cost=(cuts[j]-cuts[i])+dp[i][k]+dp[k][j];
                    mini=min(cost,mini);
                }
                dp[i][j]=mini;
            }
        }
        
        return dp[0][m-1];
    }
};