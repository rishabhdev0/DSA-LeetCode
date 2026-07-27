class Solution {
public:
    bool canShip(vector<int>& weights , int days , int mid){
       int dayCount = 1;
       int sum = 0;
       for(int  i = 0 ; i <  weights.size() ; i++){
          sum += weights[i];
          if(sum > mid){
            dayCount++;
            sum  = weights[i];

          }
       }
       return dayCount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin() , weights.end());
        int high = accumulate(weights.begin() , weights.end() , 0);
        int result = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canShip(weights , days , mid )){
                result = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return result;
    }
};