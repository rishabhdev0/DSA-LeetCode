class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        // Max heap to store pairs of (absolute difference, value)
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < n; i++){
            int diff = abs(arr[i] - x);
            pq.push({diff, arr[i]});
            
            // Maintain only k elements in heap
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> result;
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            result.push_back(top.second); 
        }
        
        // Sort the result as required by problem
        sort(result.begin(), result.end());
        return result;
    }
};