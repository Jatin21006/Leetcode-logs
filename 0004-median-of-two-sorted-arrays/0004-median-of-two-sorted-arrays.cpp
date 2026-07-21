class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();

        int low = 0;
        int high = n;

        while(low <= high){

            int mid1 = low + (high-low)/2;
            int mid2 = (n + m + 1)/2 - mid1;

            int L1 = INT_MIN;
            int L2 = INT_MIN;
            int R1 = INT_MAX;
            int R2 = INT_MAX;

            if(mid1 > 0) L1 = nums1[mid1-1];
            if(mid1 < n) R1 = nums1[mid1];

            if(mid2 > 0) L2 = nums2[mid2-1];
            if(mid2 < m) R2 = nums2[mid2];

            if(L1 <= R2 && L2 <= R1){

                if((n+m)%2==0)
                    return (max(L1,L2)+min(R1,R2))/2.0;
                else
                    return max(L1,L2);
            }

            else if(L2 > R1)
                low = mid1 + 1;

            else
                high = mid1 - 1;
        }

        return 0;
    }
};