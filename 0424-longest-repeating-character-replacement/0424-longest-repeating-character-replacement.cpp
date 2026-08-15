class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int L=0,maxLen=0,maxFreq=0;
        for(int R=0;R<s.size();R++){
            freq[s[R]-'A']++;
            maxFreq=max(maxFreq,freq[s[R]-'A']);
            while(R-L+1-maxFreq>k){
                freq[s[L]-'A']--;
                L++;
            }
            maxLen=max(maxLen,R-L+1);
        }
        return maxLen;


        
    }
};