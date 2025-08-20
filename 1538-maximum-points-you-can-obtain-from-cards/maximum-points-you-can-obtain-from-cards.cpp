class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int win_size = n - k;

        int total_sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if (win_size == 0) return total_sum; 

        int sum = 0, i = 0, j = 0;
        int max_point = 0;

        while (j < n) {
            sum += cardPoints[j];

            if (j - i + 1 == win_size) {
                int rem_sum = total_sum - sum;
                max_point = max(max_point, rem_sum);

                sum -= cardPoints[i];
                i++;
            }

            j++;
        }

        return max_point;
    }
};
