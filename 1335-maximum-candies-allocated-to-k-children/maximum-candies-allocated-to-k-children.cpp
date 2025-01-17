class Solution {
private:
    int find_max(const vector<int>& candies) {
        int maxi = INT_MIN;
        for (int candy : candies) {
            maxi = max(candy, maxi);  
        }
        return maxi;
    }
    bool ispossible(const vector<int>& candies, int divisor, long long k) {
        long long allocate = 0;
        for (int candy : candies) {
            allocate += candy  / divisor;
        }
        return allocate >= k;  
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int result = 0;
        int s = 1;  
        int e = find_max(candies);  
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (ispossible(candies, mid, k)) {
                result = mid;  
                s = mid + 1;   
            } else {
                e = mid - 1;  
            }
        }
        return result;
    }
};
