
class Solution {
public:
    vector<int> getNSR(vector<int>& height) {
        int n = height.size();
        stack<int> nsr;
        vector<int> right(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!nsr.empty() && height[nsr.top()] >= height[i]) {
                nsr.pop();
            }

            right[i] = nsr.empty() ? n : nsr.top();
            nsr.push(i);
        }

        return right;
    }

    vector<int> getNSL(vector<int>& height) {
        int n = height.size();
        stack<int> nsl;
        vector<int> left(n);

        for (int i = 0; i < n; i++) {
            while (!nsl.empty() && height[nsl.top()] >= height[i]) {
                nsl.pop();
            }

            left[i] = nsl.empty() ? -1 : nsl.top();
            nsl.push(i);
        }

        return left;
    }

    int Get_Max_Area(vector<int>& height) {
        int n = height.size();

        vector<int> NSR = getNSR(height);
        vector<int> NSL = getNSL(height);

        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            int width = NSR[i] - NSL[i] - 1;
            int area = width * height[i];

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);

        for (int j = 0; j < m; j++) {
            height[j] = (matrix[0][j] == '1') ? 1 : 0;
        }

        int max_Area = Get_Max_Area(height);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    height[j] = 0;
                } else {
                    height[j] += 1;
                }
            }

            max_Area = max(max_Area, Get_Max_Area(height));
        }

        return max_Area;
    }
};
