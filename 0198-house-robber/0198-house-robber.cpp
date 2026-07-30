class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return nums[0];
        
        int last=0;
        int mid=nums[0];
        int curr=nums[1];
        
        for(int i=2;i<n;i++){
            int temp=curr;
            curr=nums[i]+max(last,mid);
            last=mid;
            mid=temp;
        }
        return max(curr,mid);

        
    }
};