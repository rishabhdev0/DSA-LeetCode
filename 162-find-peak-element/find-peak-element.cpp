class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
      int s=0;
      int e=nums.size()-1;
      while(s<=e){
        int mid=s+(e-s)/2;
           if ((mid == 0 || nums[mid] >= nums[mid - 1]) && (mid == nums.size() - 1 || 
           nums[mid] >= nums[mid + 1])) {
    return mid;
}
        else if(mid>0 && nums[mid-1]>nums[mid]){
            e=mid-1;
        }
        else{
        s=mid+1;
        }
      }
      return -1;
         
      
    }
};


// class Solution {
// public:
//     int findPeakElement(vector<int>& nums){
//         if(nums.empty()) return -1;
//          if(nums.size()==1) return  0;
//           if (nums.size()== 2) {
//             return (nums[0] > nums[1]) ? 0 : 1;  
//         }

//        for(int i=1;i<nums.size();i++){
//         if (nums[i]<=nums[i-1]){
//             return i-1;
//         }
        
//        }
//        return -1;
//     }
// };