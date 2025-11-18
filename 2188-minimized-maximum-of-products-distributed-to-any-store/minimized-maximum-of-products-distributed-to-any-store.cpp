class Solution {
private:
    bool canDistribued(vector<int>& quantities , int n , int mid){
        int stores_needed = 0;
        for(int quantity : quantities){
            stores_needed +=  (quantity + mid - 1) / mid;  
        }
        return stores_needed <= n;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canDistribued(quantities, n, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
