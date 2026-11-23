class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        set<int> seen(arr.begin(), arr.end());

        int count = 0;
        int i = 1;

        while (true) {
            if (!seen.count(i)) {
                count++;

                if (count == k) {
                    return i;
                }
            }
            i++;
        }

        return -1;
    }
};