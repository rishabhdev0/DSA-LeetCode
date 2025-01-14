class Solution {
public:
int find_max(vector<int>piles){
    int maxi=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++){
        maxi=max(piles[i],maxi);
    }
    return maxi;
}



    int check(vector<int>& piles, int h, int mid) {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            ans += (piles[i] / mid);
            if (piles[i] % mid != 0) {
                ans++;
            }
        }
        return ans <= h;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = find_max(piles);

        while (low < high) {
            int mid = (low + high) >> 1;
            if (check(piles, h, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};