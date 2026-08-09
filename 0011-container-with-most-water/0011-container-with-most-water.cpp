class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        int maxArea=min(height[0],height[n-1])*(n-1);
        while(left<right){
            if(height[left]<height[right]){
                left++;
                int area=min(height[left],height[right])*(right-left);
                maxArea=max(area,maxArea);
            }
            else{
                right--;
                int area=min(height[left],height[right])*(right-left);
                maxArea=max(area,maxArea);
            }

        }
        return maxArea;
        
    }
};