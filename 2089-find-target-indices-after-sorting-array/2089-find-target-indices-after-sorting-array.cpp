class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        auto l=lower_bound(nums.begin(),nums.end(),target);
        auto u=upper_bound(nums.begin(),nums.end(),target);
        if(l==u)return {};
        int low=l-nums.begin();
        int high=u-nums.begin();
        while(low<high){
            ans.push_back(low);
            low++;
        }
        return ans;
        
    }
};