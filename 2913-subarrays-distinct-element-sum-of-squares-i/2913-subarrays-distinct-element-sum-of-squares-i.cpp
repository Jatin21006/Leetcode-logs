class Solution {
public:
    const int MOD=1e9+7;
    int atMost(vector<int>& nums,int x){
        if(x<=0)return 0;
        int L=0;
        long long ans=0;
        unordered_map<int,int> freq;
        for(int R=0;R<nums.size();R++){
            freq[nums[R]]++;
            while(freq.size()>x){
                freq[nums[L]]--;
                if(freq[nums[L]]==0)freq.erase(nums[L]);
                L++;
            }
            ans+=R-L+1;
        }
        return ans%MOD;
    }
    int count(vector<int>& nums,int x){
       return (atMost(nums, x) - atMost(nums, x - 1) + MOD) % MOD;
    }
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int distinct=0;
        unordered_set<int> s;
        for(int x:nums){
            if(s.count(x))continue;
            distinct++;
            s.insert(x);
        }
        vector<int> disCnt(distinct+1,0);
        long long ans=0;
        for(int i=1;i<=distinct;i++){
            disCnt[i]=count(nums,i);
            ans+=(((1LL*i*i)%MOD)*disCnt[i])%MOD;
        }
        return ans%MOD;
    }
};