class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.length();

        // Case 1: Make all 'T'
        int i = 0, j = 0;
        int false_count = 0;
        int all_true = 0;

        while (j < n) {
            if (answerKey[j] == 'F') false_count++;

            while (false_count > k) {
                if (answerKey[i] == 'F') false_count--;
                i++;
            }

            all_true = max(all_true, j - i + 1);
            j++;
        }

        // Case 2: Make all 'F'
        i = 0, j = 0;
        int true_count = 0;
        int all_false = 0;

        while (j < n) {
            if (answerKey[j] == 'T') true_count++;

            while (true_count > k) {
                if (answerKey[i] == 'T') true_count--;
                i++;
            }

            all_false = max(all_false, j - i + 1);
            j++;
        }

        return max(all_true, all_false);
    }
};