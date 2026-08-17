class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;//lastoccurrence of char and its position
        int L=0;
        int maxLen=0;
        for(int R=0;R<s.size();R++){
            if(mpp.count(s[R])){
                //here l can travel backwards
                L=max(mpp[s[R]]+1,L);
            }
            mpp[s[R]]=R;
            maxLen=max(maxLen,R-L+1);
        }
        return maxLen;
        
    }
};