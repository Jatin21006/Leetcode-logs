class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev=cost[0];
        int curr=cost[1];
        for(int i=2;i<cost.size();i++){
            int temp=curr;
            curr=cost[i]+min(prev,curr);
            prev=temp;
        }
        return min(prev,curr);
    }
};