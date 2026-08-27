class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.size();
        vector<int> freq(26,0);
        for(char c:s)freq[c-'a']++;
        int matchLen=0;
        while(matchLen<n && freq[target[matchLen]-'a']){
            freq[target[matchLen]-'a']--;
            matchLen++;
        }
        for(int i=matchLen;i>=0;i--){
            if(i<n){
                int  t=target[i]-'a';
                for(int j=t+1;j<26;j++){
                    if(freq[j]){
                    string ans=target.substr(0,i);    
                    ans+='a'+j;
                    freq[j]--;
                    //add rest of the string lexographically and return
                    for(int k=0;k<26;k++){
                        while(freq[k]){
                            ans+='a'+k;
                            freq[k]--;
                        }
                    }
                    return ans;
                    }
                }
            
            }
            if(i>0)freq[target[i-1]-'a']++;
        }

        return "";
        
    }
};