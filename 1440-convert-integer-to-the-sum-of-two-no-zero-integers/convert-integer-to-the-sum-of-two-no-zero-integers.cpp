class Solution {
private:
    bool hasZero(int num) {
        while (num > 0) {
            if (num % 10 == 0) return true; // it has zero
            num /= 10;
        }
        return false;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> result;
        for (int i = 1; i < n; i++) {   // start from 1
            int j = n - i;              // correct calculation
            if (!hasZero(i) && !hasZero(j)) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
        return {};
    }
};
