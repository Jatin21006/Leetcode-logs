class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0,i=0,j=0;
        vector<int> ch_freq(3,0);
        int n=s.size();
        while(i<n-2 && j<n){
            ch_freq[s[j]-'a']++;
            while(ch_freq[0] && ch_freq[1] && ch_freq[2]){
                ans+=n-j;
                ch_freq[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;

    }
};