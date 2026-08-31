class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L=0,sum=0;
        int ans=INT_MAX;
        for(int R=0;R<nums.size();R++){
            sum+=nums[R];
            //while valid
            while(sum>=target){
                ans=min(ans,R-L+1);
                sum-=nums[L];
                L++;
                
            }

        }
        return (ans==INT_MAX)?0:ans;

        
    }
};