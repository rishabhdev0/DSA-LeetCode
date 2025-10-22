class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total_size = n + m;
        vector<int> temp(total_size);
        
        int i = 0, j = 0, k = 0;
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]) {
                temp[k] = nums1[i];
                i++;
            } else {
                temp[k] = nums2[j];
                j++;
            }
            k++;
        }
        while(i < n) {
            temp[k] = nums1[i];
            i++;
            k++;
        }
        while(j < m) {
            temp[k] = nums2[j];
            j++;
            k++;
        }
        if(total_size % 2 == 0) {
            return (temp[total_size/2 - 1] + temp[total_size/2]) / 2.0;
        } else {
            return temp[total_size/2];
        }
    }
};