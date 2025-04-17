class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int i = 0;          
        int sum = 0;         
        int count = 0;       
        
        for (int j = 0; j < n; j++) {
            sum += arr[j];   
            
            if (j - i + 1 == k) {
                double average = sum / k;
                if (average >= threshold) {
                    count++;
                }
                sum -= arr[i];  // Remove leftmost element
                i++;            // Slide window right
            }
        }
        
        return count;
    }
};