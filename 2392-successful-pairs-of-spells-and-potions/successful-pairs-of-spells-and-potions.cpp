class Solution {
private:
    int lower_bound(int l, int r, vector<int>& potions, int minPortions) {
        int possibleindex = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (potions[mid] >= minPortions) {
                possibleindex = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return possibleindex;
    }

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        int maxPotion = potions[m - 1];  
        vector<int> answer;

        for (int i = 0; i < n; i++) {  
            long long minPortions = ceil((1.0 * success) / spells[i]);
            if (minPortions > maxPotion) {
                answer.push_back(0);
                continue;
            }
            int index = lower_bound(0, m - 1, potions, minPortions);  
            int count = (index == -1) ? 0 : m - index;
            answer.push_back(count);
        }

        return answer;
    }
};