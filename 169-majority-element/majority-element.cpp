class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // using  Boyer–Moore Majority Vote Algorithm
      int curr = 0;
      int count = 0;
      for(int num : nums){
        if(count == 0){
            curr = num;
        }
        if(curr == num){
            count++;
        }else{
            count--;
        }
      }
      return curr; 
    }
};