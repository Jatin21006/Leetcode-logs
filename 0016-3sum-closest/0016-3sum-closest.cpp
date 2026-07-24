class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=nums[0]+nums[1]+nums[2];
        if(n==3)return ans;
        for(int i=0;i<n-2;i++){
            //fix one variable
            //dimension of question are reduced
            int L=i+1;
            int R=n-1;
            while(L<R){
                int sum=nums[i]+nums[L]+nums[R];
                if(abs(target-sum)<abs(target-ans)){
                    ans=sum;
                }
                if(sum>target)R--;
                else if(sum<target)L++;
                else return sum;

            }
        }
        return ans;
        
    }
};