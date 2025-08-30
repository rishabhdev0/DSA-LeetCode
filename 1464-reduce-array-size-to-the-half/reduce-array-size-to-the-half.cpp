class Solution {
public:
    int minSetSize(vector<int>& arr) {
       int n = arr.size();
       unordered_map<int , int>freq;
       for(int i =0 ; i <  n ; i++){
        freq[arr[i]]++;
       } 
       // now using heap for the freq
       priority_queue<int>pq;
       for(auto it = freq.begin() ; it!=freq.end() ; it++){
           pq.push(it->second);
       }
      //now finding the acyual result;
      int count = 0;
      int removed = 0; //since we remove the the freq we could get n-removed to half
      int half = n/2;
      while(removed < half){
        removed +=pq.top(); // {3,4} so 4 element is being removed
        pq.top();
        pq.pop();
        count++;
      }
      return count;
    }
};