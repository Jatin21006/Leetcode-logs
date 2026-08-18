class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //state= no of 0s
        //valid state=no of 0s less than K
        //invalid state= no of 0s exceeding k
        int count=0;
        int ans=0;
        int L=0;
        int n=nums.size();
        for(int R=0;R<n;R++){
            if(nums[R]==0)count++;
            while(count>k){
                if(nums[L]==0)count--;
                L++;
            }
            ans=max(ans,R-L+1);
        }
        return ans;
        
    }
};