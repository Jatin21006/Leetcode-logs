class Solution {
public:
    int climbStairs(int n) {
        int curr=1;
        int prev=1;
        for(int i=2;i<=n;i++){
            int temp=curr;
            curr=curr+prev;
            prev=temp;

        }
        return curr;
        
    }
};