class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxArea=0;
        stack<int> st;//increasing monotonic stack
        for(int i=0;i<=n;i++){
            int currentHeight=(i==n)?0:heights[i];
            while(!st.empty() && heights[st.top()]>currentHeight){
                int h=heights[st.top()];
                st.pop();

                int nse=i;
                int pse=(st.empty())?-1:st.top();
                int width=nse-pse-1;

                int area=h*width;
                maxArea=max(maxArea,area);

            }
            st.push(i);
        }
        return maxArea;

        
    }
};