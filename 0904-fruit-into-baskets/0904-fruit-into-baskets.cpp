class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> mp;//type of fruit,its last occurrence
        int L=0,maxLen=0;
        for(int R=0;R<n;R++){
            //state update
            mp[fruits[R]]=R;
            //check validity
            while(mp.size()>2){
                //restore validity
                L=INT_MAX;
                for(auto it:mp){
                    L=min(L,it.second+1);
                }
                mp.erase(fruits[L-1]);

            }
            //update answer
            maxLen=max(maxLen,R+1-L);
        }
        return maxLen;
        
    }
};