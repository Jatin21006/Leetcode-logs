class Solution {
public:
    int f(vector<int>& nums, int k){
        if(k<0)return 0;
        int count=0;
        int ans=0;
        int L=0;
        for(int R=0;R<nums.size();R++){
            if(nums[R]%2==1)count++;
            while(count>k){
                if(nums[L]%2==1)count--;
                L++;
            }
            ans+=R-L+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (f(nums,k)-f(nums,k-1));
        
    }
};