class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int start = 0, end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
                (mid == n - 1 || nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }

            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                int leftLen  = mid - 1 - start;   
                int rightLen = end - mid;         

                if (leftLen % 2 == 1)
                    end = mid - 2;   // odd side → problem here
                else
                    start = mid + 1;
            }
            // case 3: mid is paired with right
            else {
                int leftLen  = mid - start;       // elements before the pair
                int rightLen = end - (mid + 1);   // elements after the pair

                if (rightLen % 2 == 1)
                    start = mid + 2; // odd side --- element must be here
                else
                    end = mid - 1;
            }
        }
        return -1;
    }
};