class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int> dp(n,1);
        vector<int> tails;
        tails.push_back(obstacles[0]);
        for(int i=1;i<n;i++){
            auto it=upper_bound(tails.begin(),tails.end(),obstacles[i]);
            if(it==tails.end()){
                tails.push_back(obstacles[i]);
                dp[i]=tails.size();
            }
            else{
                *it=obstacles[i];
                dp[i]+=it-tails.begin();
            }
        }
        return dp;
        
    }
};