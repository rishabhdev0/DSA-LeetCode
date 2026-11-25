class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if(n > m){
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = n;

        while(low <= high){
            int px = low + (high - low) / 2;
            int py = (m+n+1)/2 - px;

            int x1 = (px == 0) ? INT_MIN : nums1[px - 1];
            int x3 = (px == n) ? INT_MAX : nums1[px];

            int x2 = (py == 0) ? INT_MIN : nums2[py - 1];
            int x4 = (py == m) ? INT_MAX : nums2[py];

            if(x1 <= x4 && x2 <= x3){
                if((m+n) % 2 == 0){
                    return (max(x1, x2) + (double)min(x3, x4)) / 2.0;
                }

                return max(x1, x2);
            }
            else if(x1 > x4){
                high = px - 1;
            }
            else{
                low = px + 1;
            }
        }

        return -1;
    }
};
