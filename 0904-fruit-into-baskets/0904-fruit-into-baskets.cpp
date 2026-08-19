class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> mp;//type of fruit,its count
        int L=0,maxLen=0;
        for(int R=0;R<n;R++){
            //state update
            mp[fruits[R]]++;
            //check validity
            while(mp.size()>2){
                mp[fruits[L]]--;
                if(mp[fruits[L]]==0)mp.erase(fruits[L]);
                L++;
            }
            //update answer
            maxLen=max(maxLen,R+1-L);
        }
        return maxLen;
        
    }
};