class Solution {
public:
 int longestMountain(vector<int>& arr) {
    int n = arr.size();
    int longest = 0; // Variable to store the length of the longest mountain

    // Traverse the array to find peaks
    for (int i = 1; i < n - 1; i++) {
        // Check if the current element is a peak
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
            int left = i - 1;
            int right = i + 1;

            // Expand to the left to find the start of the increasing sequence
            while (left > 0 && arr[left - 1] < arr[left]) {
                left--;
            }

            // Expand to the right to find the end of the decreasing sequence
            while (right < n - 1 && arr[right] > arr[right + 1]) {
                right++;
            }

            // Calculate the length of the mountain
            int length = right - left + 1;

            // Update the longest mountain length
            if (length > longest) {
                longest = length;
            }

            i = right;
        }
    }

    return longest;
}
};