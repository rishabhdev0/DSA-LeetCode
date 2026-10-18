class Solution {
public: 
    int const mod = 1e9 + 7;

    int countPairs(vector<int>& deliciousness) {
        int n = deliciousness.size();
        long long count = 0;
        unordered_map<int , int>freq;
        for(int i = 0 ; i < n ; i++){
            int sum = deliciousness[i];
            for(int j =  0 ; j <= 21 ; j++){
                int diff = (1 << j) - sum;
                if(diff < 0) continue;
                if(freq.count(diff)){
                    count += freq[diff];
                    count %= mod;
                }
            }
            freq[sum]++;
        }
        return count;
    }
};