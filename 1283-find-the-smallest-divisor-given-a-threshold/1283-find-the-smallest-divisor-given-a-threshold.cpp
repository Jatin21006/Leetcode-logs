class Solution {
public:
    int result(vector<int> &nums,int x){
        int sum=0;
        for(int num:nums){
            sum+=(num+x-1)/x;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=1;
        int high=nums[n-1];
        while(low<=high){
            int mid=((high-low)/2)+low;
            int res=result(nums,mid);
            //divisor too small
            if(res>threshold){
                low=mid+1;
            }
            else high=mid-1;

        }
        return low;
        
    }
};