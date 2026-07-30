class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int ans=0;
        int i=1;
        while(n>0){
            if(n<=8){
                ans+=n*i;
                break;
            }
            ans+=8*i;
            i++;
            n-=8;

        }
        return ans;

        
    }
};