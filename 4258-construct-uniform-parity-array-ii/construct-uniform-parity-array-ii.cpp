class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        bool hasOdd = false;
        bool hasEven = false;

        for (int x : nums1) {
            if (x % 2)
                hasOdd = true;
            else
                hasEven = true;
        }

        
        if (!hasOdd || !hasEven)
            return true;

        if (mn % 2 == 1)
            return true;

        return false;
    }
};