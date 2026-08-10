class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        vector<int>ans;
        while(l<=r){
            if(target==numbers[l]+numbers[r]){
                vector<int>ans;
                ans.push_back(l+1);
                 ans.push_back(r+1);
                 return ans;
            }else if(target>numbers[l]+numbers[r]){
                l++;
            }else{
                r--;
            }
        }
        return ans;
    }
};