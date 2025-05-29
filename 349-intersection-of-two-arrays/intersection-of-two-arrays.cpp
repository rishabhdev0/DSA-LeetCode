class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int , int> freq;
        vector<int>result;
        for(int num:nums1){ // put all elem in freq
            freq[num]++;
        }

        for(int num:nums2){ // travse through nums 2 and all the intersection
            if(freq[num]>0){ 
                result.push_back(num);
                freq[num] =0; // for uniquesness
            }
        }
return result;
    }
};