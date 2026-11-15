class Solution {
public:
    bool isPossible(vector<int>& nums , int k , int mid){
        // using sliding window here;
        int i =0;
        int j = 0;
        int count = 0;

        while(j < nums.size()){
            int dist = nums[j] - nums[i];
            while(dist > mid){
                i++;
                dist = nums[j] - nums[i];
            }
            count += j - i;
            j++;
        }
        return count >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int low = 0;
        int high = nums[n-1] - nums[0];
        int result = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(nums , k , mid)){
                high = mid - 1;
                result = mid;
            }else{
                low = mid + 1;
            }
        }
        return result;
    }
};