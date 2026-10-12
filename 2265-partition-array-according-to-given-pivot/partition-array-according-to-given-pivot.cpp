
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int less_than_pivot = 0;
        int pivot_count = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] < pivot){
                less_than_pivot++;
            }else if(nums[i] == pivot){
                pivot_count++;
            }
        }

        int i = 0;
        int j = less_than_pivot + pivot_count;
        vector<int> result(n, pivot);

        for(int k = 0; k < n; k++){
            if(nums[k] < pivot){
                result[i] = nums[k];
                i++;
            }else if(nums[k] > pivot){
                result[j] = nums[k];
                j++;
            }
        }

        return result;
    }
};
