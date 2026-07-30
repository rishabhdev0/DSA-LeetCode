class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<int , int>freq;
        int result = 0;
        int start = 2;
        for(char &ch : word){
            if(start > 9){
                start = 2; // start over;
            }
            freq[start]++;
            result += freq[start];
            start++;
        }
        return result;
    }
};