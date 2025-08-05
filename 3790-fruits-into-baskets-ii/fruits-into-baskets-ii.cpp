class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int un_placed = 0;
        
        for (int i = 0; i < fruits.size(); i++) {
            bool placed = false;

            for (int j = 0; j < baskets.size(); j++) {
                if (fruits[i] <= baskets[j]) {
                    baskets.erase(baskets.begin() + j); // erase so dont get duplica
                    placed = true;
                    break;
                }
            }

            if (!placed) un_placed++;
        }

        return un_placed;
    }
};
