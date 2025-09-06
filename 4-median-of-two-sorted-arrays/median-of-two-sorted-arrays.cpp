class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> temp;
        int i = 0;
        int j = 0;
        // merge
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        // remaining
        while (i < n) temp.push_back(nums1[i++]);
        while (j < m) temp.push_back(nums2[j++]);

        int new_length = temp.size();
        if (new_length % 2 == 1) {
            return (double)temp[new_length/2];
        } else {
            return ((double)temp[new_length/2 - 1] + (double)temp[new_length/2]) / 2.0;
        }
    }
};
