class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n - 1;  
        int max_area = 0;
        
        while (i < j) {
            int width = j - i;
            int heights = min(height[i], height[j]);
            int curr_area = width * heights;
            max_area = max(max_area, curr_area);
            
            if (height[i] < height[j]) {  
                i++;
            } else {
                j--;
            }
        }
        
        return max_area;
    }
};