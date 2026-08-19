class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;//lastoccurence
        int L=0;
        int ans=0;
        for(int R=0;R<s.size();R++){
            mp[s[R]]=R;
            if(mp.size()==3){
                int minIndex=INT_MAX;
                for(auto it:mp)minIndex=min(minIndex,it.second);
                ans+=minIndex+1;

            }

        }
        return ans;
        
    }
};