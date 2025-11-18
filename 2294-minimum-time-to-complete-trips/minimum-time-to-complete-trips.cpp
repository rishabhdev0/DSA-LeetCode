class Solution {
private:
    bool canTravel(vector<int>& time, int totalTrips, long long mid) {
        long long trips = 0;
        for(int t : time){
            trips += mid / t;  
        }
        return trips >= totalTrips; 
    }

public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long result = -1;
        long long low = 1;
        long long high = (long long)*max_element(time.begin(), time.end()) * totalTrips;
        
        while(low <= high){
            long long mid = low + (high - low) / 2;
            
            if(canTravel(time, totalTrips, mid)){
                result = mid;
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }
        
        return result;
    }
};