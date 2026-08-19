class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int m=n-k;
        int sum=0;
        for(int i=0;i<m;i++)sum+=cardPoints[i];
        int ans=sum;
        for(int i=m;i<n;i++){
            sum+=cardPoints[i];
            sum-=cardPoints[i-m];
            ans=min(sum,ans);
        }
        int total=accumulate(cardPoints.begin(),cardPoints.end(),0);
        return total-ans;
    }
};