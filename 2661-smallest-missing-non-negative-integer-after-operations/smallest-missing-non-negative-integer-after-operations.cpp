class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int , int>map;
        for(int num : nums){
            int r = ((num % value) + value)%value; // handle negative module
            map[r]++;
        }
        // find MEX;
        int MEX = 0;
        while(map[MEX % value] > 0){
            map[(MEX%value)]--;
            MEX++;
        }
        return MEX;
    }
};