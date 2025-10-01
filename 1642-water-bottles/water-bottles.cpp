class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        while(numBottles >= numExchange){
            int newBottle = numBottles / numExchange;
            count += newBottle;
            numBottles = newBottle + (numBottles % numExchange); // new bottle + 9 % 3
        }
        return count;
    }
};