class Solution {
public:
    bool canEat(vector<int>& piles, int deadline, int mid) {
        long long hours = 0;

        for(int i = 0 ; i < piles.size() ; i++){
            hours += (piles[i] + mid -1)/ mid;
            if(hours > deadline) return false;
        }
        return hours <= deadline;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high) {
            int mid = low + (high - low) / 2;

            if(canEat(piles, h, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
