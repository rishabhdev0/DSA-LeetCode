class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        int i = 0, j = 0;
        int window_sum = 0;
        int max_un_satisfied = 0;

        while (j < n) {
            window_sum += customers[j] * grumpy[j];

            if (j - i + 1 == minutes) {
                max_un_satisfied = max(max_un_satisfied, window_sum);
                window_sum -= customers[i] * grumpy[i];
                i++;
            }
            j++;
        }

        int count = 0;
        for (int k = 0; k < n; k++) {
            count += customers[k] * (1 - grumpy[k]);
        }

        return count + max_un_satisfied;
    }
};