class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int s=nums1.size()-1;
        int e=nums2.size()-1;
        while(s>=0 && e>=0){
            if(nums1[s]==nums2[e]){
                 result.push_back(nums1[s]);
                s--;
                e--;
                // result.push_back(s);
            }
            else if(nums1[s]>nums2[e]){
                s--;
            }
            else{
                e--;
            }
        }
        return result;
    }
};