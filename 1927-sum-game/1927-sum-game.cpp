class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int sum1=0,sum2=0;
        int cnt1=0,cnt2=0;
        for(int i=0;i<n/2;i++){
            if(num[i]=='?')cnt1++;
            else sum1+=num[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            if(num[i]=='?')cnt2++;
            else sum2+=num[i]-'0';
        }
        //agar odd no of ? hue toh alice will always since she makes the last move
        if ((cnt1 + cnt2) % 2)return true;
        //kis side jyada ? hai
        if(cnt1>cnt2 && sum1>sum2)return true;
        if(cnt2>cnt1 && sum2>sum1)return true;
        int changes=abs(cnt1-cnt2);
        int diff=abs(sum1-sum2);
        //max sum jo alice bana sakti hai
        int A1=((changes+1)/2)*9;
        //max sum jo bob bana sakta hai
        int B1=(changes/2)*9;
        if(A1>diff)return true;
        if(B1<diff)return true;
        return false;

    }
};