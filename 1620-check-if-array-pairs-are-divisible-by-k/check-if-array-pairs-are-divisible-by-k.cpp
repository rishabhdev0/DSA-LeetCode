class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int , int>freq;
        for(int ar : arr){
            int mod = ((ar % k) + k) % k;
            freq[mod]++;
        }
        for(auto it : freq){
            int rem = it.first;
            int times = it.second;
            if(rem == 0){
                if(times % 2 != 0){
                    return false;
                }
            }else{
                int needed = k - rem;
                if(freq[needed] != times){
                    return false;
                }
            }
        }
        return true;
    }
};