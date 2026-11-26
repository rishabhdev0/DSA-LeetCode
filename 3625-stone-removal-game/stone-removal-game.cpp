class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool aliceTurn = true;

        while (stones > 0) {
            if (n < stones) {
                return !aliceTurn;
            }

            n -= stones;
            stones--;
            aliceTurn = !aliceTurn;
        }

        return false;
    }
};