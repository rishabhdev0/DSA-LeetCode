class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long , int>freq;
        for(int num : nums){
            freq[num]++;
        }
        int ans = 0;
        if(freq.count(1)){
            int one = freq[1];
            if(one % 2 == 0) one--;
            ans = max(ans , one);
        }


        for(auto &it : freq){
            long long x = it.first;
            if(x == 1) continue;
            int len = 0;
            while(freq.count(x)){
                if(freq[x] >= 2){
                    len += 2;
                    x = x * x;
                }else{
                    len += 1;
                    break;
                }
            }
            if(len % 2 == 0) len--;
            ans = max(ans , len);
        }
        return ans;
    }
};