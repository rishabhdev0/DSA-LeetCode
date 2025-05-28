class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int count_a = 0, count_b = 0, count_c = 0;

        for (char ch : s) {
            if (ch == 'a') count_a++;
            else if (ch == 'b') count_b++;
            else count_c++;
        }

        if (count_a < k || count_b < k || count_c < k) {// if k>count we cannot dele
            return -1;
        }

        int i = 0, j = 0;
        int window_size = 0;

        while (j < n) {
            if (s[j] == 'a') count_a--;
            else if (s[j] == 'b') count_b--;
            else count_c--;

            while (i <= j && (count_a < k || count_b < k || count_c < k)) {
                if (s[i] == 'a') count_a++;
                else if (s[i] == 'b') count_b++;
                else count_c++;
                i++;
            }

            window_size = max(window_size, j - i + 1);
            j++;
        }

        return n - window_size;
    }
};
