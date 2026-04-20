class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        stack<int> greater;                  
        vector<int> temp(10001, -1);         

        for(int i = n - 1; i >= 0; i--){
            int ele = nums2[i];
            while(!greater.empty() && greater.top() <= ele)  
                greater.pop();

            temp[ele] = greater.empty() ? -1 : greater.top();
            greater.push(ele);               
        }

        vector<int> result(nums1.size());
        for(int i = 0; i < nums1.size(); i++)
            result[i] = temp[nums1[i]];

        return result;
    }
};