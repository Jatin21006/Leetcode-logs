class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<long long> diff(n);
        for(int i=0;i<n;i++){
            diff[i]=abs(nums1[i]-nums2[i]);
        }
        long long  k=1LL*k1+k2;
        long long total=accumulate(diff.begin(),diff.end(),0LL);
        if(k>=total)return 0;
        long long ans=0;
        long long maxEl=*max_element(diff.begin(),diff.end());
        vector<long long> cnt(maxEl+1,0);
        for(long long d:diff)cnt[d]++;
        for(long long i=maxEl;i>0 && k>0;i--){
            if(k>=cnt[i]){
                k-=cnt[i];
                cnt[i-1]+=cnt[i];
                cnt[i]=0;
            }
            else{
                cnt[i]-=k;
                cnt[i-1]+=k;
                k=0;
                break;
            }
        }
        for(long long i=1;i<cnt.size();i++)ans+=1LL*(cnt[i]*(i*i));
        return ans;
    }
};