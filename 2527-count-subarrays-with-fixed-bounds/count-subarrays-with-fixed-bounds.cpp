class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long answer = 0;

        int minIdx = -1;
        int maxIdx = -1;
        int culprit = -1;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] < minK || nums[i] > maxK){
                culprit = i;
            }
            if(nums[i] == minK){
                minIdx = i;
            }
            if(nums[i] == maxK){
                maxIdx = i;
            }
            int smaller = min(minIdx , maxIdx);
            int valid = smaller - culprit;
            if(valid > 0){
                answer += valid;
            }
        }
        return answer;
    }
};