class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int max_fruit = 0;
        unordered_map<int , int>freq;
        int i = 0;
        int j = 0;;
        while(j < n){
           freq[fruits[j]]++;
           while(freq.size() > 2){
               freq[fruits[i]]--;
               if(freq[fruits[i]] == 0){
                freq.erase(fruits[i]);
               }
               i++;
           }
           max_fruit = max(max_fruit , j - i + 1);
           j++;
        }
        return max_fruit;
    }
};