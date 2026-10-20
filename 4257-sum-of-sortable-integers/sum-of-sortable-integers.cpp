class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int>sorted_nums = nums;
        sort(sorted_nums.begin() , sorted_nums.end());
        int sum_count = 0;
        for(int k = 1 ; k <=n ; k++){
            if(n%k != 0) continue;
            bool valid = true;
            for(int j = 0 ; j < n / k && valid ; j++){
                int start = j * k;
                int dip = 0;
                int rot_start = 0;
                for(int i = 0 ; i < k ; i++){
                    if(nums[start + i] > nums[start + (i + 1)%k]){
                        dip++;
                        rot_start = (i + 1)%k;
                    }
                }    
                    if(dip > 1){
                        valid = false;
                        break;
                    }
                    // verify your answer;
                   for(int i = 0 ; i < k ; i++){
                       if(nums[start + (rot_start + i) % k] != sorted_nums[start + i]){
                           valid = false;
                           break;
                       }
                   }
                }
            if(valid){
                sum_count += k;
            }
        }
        return sum_count;
    }
};