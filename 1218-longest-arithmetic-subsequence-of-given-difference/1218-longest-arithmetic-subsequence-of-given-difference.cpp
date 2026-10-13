class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        vector<int> dp(n,1);
        unordered_map<int,int> mpp;//element,count
        mpp[arr[0]]=1;
        for(int i=1;i<n;i++){
            if(mpp[arr[i]-difference]){
                int a=mpp[arr[i]-difference];
                dp[i]=a+1;
                mpp[arr[i]]=dp[i];
            }
            else mpp[arr[i]]=max(mpp[arr[i]],1);
        }
        return *max_element(dp.begin(),dp.end());

        
    }
};