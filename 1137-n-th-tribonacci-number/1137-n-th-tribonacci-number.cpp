class Solution {
public:
    int tribonacci(int n) {
        int last=0;
        int mid=1;
        int curr=1;
        if(n==0 ||n==1)return n;
        for(int i=3;i<=n;i++){
            int temp=curr;
            curr+=last+mid;
            last=mid;
            mid=temp;
        }
        return curr;
        
    }
};