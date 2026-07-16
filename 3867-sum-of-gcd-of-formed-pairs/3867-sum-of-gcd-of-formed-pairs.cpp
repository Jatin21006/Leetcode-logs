class Solution {
public:
    int gcd(int a,int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxEl(n,0);
        maxEl[0]=nums[0];
        vector<int> prefixGcd(n);
        prefixGcd[0]=nums[0];
        for(int i=1;i<n;i++){
            maxEl[i]=max(maxEl[i-1],nums[i]);
            prefixGcd[i]=gcd(nums[i],maxEl[i]);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int left=0;
        int right=n-1;
        long long ans=0;
        while(left<right){
            ans+=gcd(prefixGcd[left],prefixGcd[right]);
            left++;
            right--;
        }
        return ans;
        
        
    }
};