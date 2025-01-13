/*

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

       
        if (nums[s] <= nums[e]) {
            return nums[s]; 
        }

        while (s <= e) {
            int mid = s + (e - s) / 2;

            
            if ((mid == 0 || nums[mid] < nums[mid - 1]) && 
                (mid == nums.size() - 1 || nums[mid] < nums[mid + 1])) {
                return nums[mid];
            }

            
            if ( nums[s]<= nums[mid]) {
                s = mid+1 ; 
            }
          
            else {
                e = mid ; 
            }
        }

        return 0; 
    }
};

*/
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (nums[m] < nums[r])
        r = m;
      else
        l = m + 1;
    }

    return nums[l];
  }
};
