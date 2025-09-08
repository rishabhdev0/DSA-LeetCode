class Solution {
public:
    int minSetSize(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>freq;
        for(int i = 0 ; i < n ; i++){
            freq[nums[i]]++;
        }

        // building the heap 
        priority_queue<int>pq;
        for(auto it = freq.begin() ; it!=freq.end() ; it++){
            pq.push(it->second); // freq based map heap
        }
        // building tht result 
        int removed = 0;
        int result = 0 ;
        int half  = n/2;
        while(removed < half){
            removed +=  pq.top(); // {3,4 } --->4 will be added;
            pq.top();
            pq.pop();
            result++;
        }
        return result;
    }
};