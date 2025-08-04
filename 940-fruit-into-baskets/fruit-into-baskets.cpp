class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int , int> freq;
        int i = 0;
        int j = 0;
        int result = 0;
        while(j < n){
            freq[fruits[j]]++;
            while(freq.size() > 2){
                freq[fruits[i]]--;
                if(freq[fruits[i]]==0){
                    freq.erase(fruits[i]);
                }
                i++;
            }
            result = max(result , j-i+1);
            j++;
        }
        return result;
    }
};