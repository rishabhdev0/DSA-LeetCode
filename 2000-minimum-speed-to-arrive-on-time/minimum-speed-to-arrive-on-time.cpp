class Solution {
public:
    bool canTravel(vector<int>& dist, double hour, int speed) {
        double totalTime = 0.0;

        for(int i = 0; i < dist.size() - 1; i++){
            totalTime += ceil((double)dist[i] / speed);
        }

        totalTime += (double)dist.back() / speed;

        return totalTime <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1;
        int high = 1e9;
        int result = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canTravel(dist, hour, mid)){
                result = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return result;
    }
};
