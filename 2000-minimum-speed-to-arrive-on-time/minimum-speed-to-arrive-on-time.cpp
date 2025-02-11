class Solution {
private:
    int find_max(vector<int>& dist){
        int maxi = INT_MIN;
        for(int i = 0; i < dist.size(); i++){
            maxi = max(maxi, dist[i]);
        }
        return maxi;
    }

    bool binarysearch(vector<int>& dist, double hour, int speed){
        double total_time = 0;
        for(int i = 0; i < dist.size(); i++){
            if(i != dist.size() - 1){
                total_time += ceil((double)dist[i] / speed);
            } else {
                total_time += (double)dist[i] / speed;
            }
        }
        return total_time <= hour;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 1;
        // int e = find_max(dist);
        int e = 1e7;
        int result = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(binarysearch(dist, hour, mid)){
                result = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return result;
    }
};