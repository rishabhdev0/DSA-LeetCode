int firstocc(vector<int> &arr, int key) {
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;
    while (start <= end) {  
       int mid = start + (end - start) / 2;  
        
        if (arr[mid] == key) {
            ans = mid;   
            end = mid -1 ; 
        }
        else if (key > arr[mid]) {
            start = mid + 1;  
        }
        else {
            end = mid - 1;  
        }
    }
    
    return ans; 
}

int lastocc(vector<int> &arr,  int key) {
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;
    
    while (start <= end) {  
        int mid = start + (end - start) / 2;  
        
        if (arr[mid] == key) {
            ans = mid;   
            start = mid + 1; 
        }
        else if (key > arr[mid]) {
            start = mid + 1;  
        }
        else {
            end = mid - 1; 
        }
    }
    
    return ans; 
}
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     vector<int> result(2, -1);
    
    result[0] = firstocc(nums, target);  
    result[1] = lastocc(nums, target);   
    
    return result;
    }
};