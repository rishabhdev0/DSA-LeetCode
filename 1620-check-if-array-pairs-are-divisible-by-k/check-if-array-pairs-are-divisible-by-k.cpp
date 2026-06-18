class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> freq;

        for(int x : arr) {
            int rem = ((x % k) + k) % k;
            freq[rem]++;
        }

        if(freq[0] % 2) return false;

        for(int i = 1; i < k; i++) {
            if(i == k - i) {
                if(freq[i] % 2) return false;
            }
            else {
                if(freq[i] != freq[k - i])
                    return false;
            }
        }

        return true;
    }
};