class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int L=0;
        for(int R=1;R<n;R++){
            if(nums[R]<=nums[R-1])L=R;
            ans=max(ans,R-L+1);

        }
        L=0;
        for(int R=1;R<n;R++){
            if(nums[R]>=nums[R-1])L=R;
            ans=max(ans,R-L+1);
        }
        return ans;
    }
};