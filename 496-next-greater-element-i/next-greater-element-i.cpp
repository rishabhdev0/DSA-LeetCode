class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);

        for (int i = 0; i < nums1.size(); ++i) {
            // find index in nums2
            int indexInNums2 = -1;
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums2[j] == nums1[i]) {
                    indexInNums2 = j;
                    break;
                }
            }

           // now check for greater element
            for (int j = indexInNums2 + 1; j < nums2.size(); ++j) {
                if (nums2[j] > nums1[i]) {
                    result[i] = nums2[j];
                    break;
                }
            }
        }

        return result;
    }
};
