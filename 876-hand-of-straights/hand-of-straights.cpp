class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int groupSize) {
        int n = nums.size();
        if(n % groupSize) return false;

        map<int , int>freq;

        for(int num : nums){
            freq[num]++;
        }

     while(!freq.empty()){
        int curr = freq.begin()->first;
        for(int i = 0 ; i < groupSize ; i++){
            if(freq[curr + i] == 0){
                return false;
            }
            freq[curr + i]--;
            if(freq[curr + i] == 0){
                freq.erase(curr + i);
            }
        }
     }
        return true;
    }
};