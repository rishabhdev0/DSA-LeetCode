class Solution {
public:
    int maxProduct(int n) {
        int prev = 0;
        int result = 0;

        while (n > 0) {
            int curr = n % 10;

            result = max(result, curr * prev);
            prev = max(prev, curr);

            n /= 10;
        }

        return result;
    }
};