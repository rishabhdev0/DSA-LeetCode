class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int max_mount = 0;

        for (int i = 1; i < n - 1; i++) {
            // find peak 
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;

            //    left side expand karo
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }

                // expand karo right side 
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }

                max_mount = max(max_mount, right - left + 1);
            }
        }
        return max_mount;
    }
};
