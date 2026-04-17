class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(piles.begin() , piles.end());
        int sum = 0;
        for(int i = n / 3 ; i < n ; i +=2){   // why n/3 since bob is nigga and picks smallest
            sum += piles[i];
        }
        return sum;
    }
};