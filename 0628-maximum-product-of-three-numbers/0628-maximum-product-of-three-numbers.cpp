class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=0;
        while(mid<n){
            if(nums[mid]>=0)break;
            mid++;
        }
        //case of all positive and all negatives or the case of one negative and two positive forced
        if(mid==n || mid==0 || n==3){
            return nums[n-1]*nums[n-2]*nums[n-3];
        }
        //case of one positive and two negatives
        int sum=max(nums[n-2]*nums[n-3],nums[0]*nums[1]);
        return sum*nums[n-1];
        
    }
};