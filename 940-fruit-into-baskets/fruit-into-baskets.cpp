class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> count;
        int max_fruits = 0;
        int i = 0, j = 0;
        
        while (j < n) {
            count[fruits[j]]++;
            
            while (count.size() > 2) {
                count[fruits[i]]--;
                if (count[fruits[i]] == 0) {
                    count.erase(fruits[i]);
                }
                i++;
            }
            
            max_fruits = max(max_fruits, j - i + 1);
            j++;
        }
        
        return max_fruits;
    }
};