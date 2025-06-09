class Solution {
public:
    bool canPlaceBalls(vector<int>& position, int m, int minForce) {
        int count = 1; // 1 ball placed
        int lastPos = position[0]; // to keep track of last pos

        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minForce) {
                count++;
                lastPos = position[i]; // update the lastpos
            }
        }

        return count >= m;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int left = 1;
        int right = position.back() - position.front();
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canPlaceBalls(position, m, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
