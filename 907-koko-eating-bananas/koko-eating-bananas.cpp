class Solution {
private:
    int find_max(vector<int>& piles) {
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size(); i++) {
            if(piles[i] > maxi) {
                maxi = piles[i];
            }
        }
        return maxi;
    }

    bool canEatInTime(vector<int>& piles, int k, int h) {
        long long hours = 0; 
        for(int i = 0; i < piles.size(); i++) {
            hours += ceil((double)piles[i] / k);
            if(hours > h) return false; 
        }
        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = find_max(piles);
        int result = -1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canEatInTime(piles, mid, h)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};