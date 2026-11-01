class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=1;
        vector<int> v;
        for(int i=1;i<n;i++){
            //evaluate
            if(nums[i]!=nums[i-1] && count==1)return -1;
            else{
                if(nums[i]==nums[i-1]) count++;
                else {
                    v.push_back(count);
                    count=1;
                    }
            }
        }
        if(count==1)return -1;
        v.push_back(count);
        //making entire array is possible
        int ans=0;
        for(int x:v){
            if(x%3)ans+=x/3+1;
            else ans+=x/3;
        }
        return ans;

        
    }
};