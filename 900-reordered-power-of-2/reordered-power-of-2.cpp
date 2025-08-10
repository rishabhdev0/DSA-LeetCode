#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> getFreq(int num) {
        vector<int> freq(10, 0); 
        while (num > 0) {
            freq[num % 10]++;
            num /= 10;
        }
        return freq;
    }

public:
    bool reorderedPowerOf2(int n) {
        vector<int> target = getFreq(n);

        for (int i = 0; i < 31; i++) { 
            int power_compute = 1 << i; // 2^i
            vector<int> targetfreq = getFreq(power_compute);
            if (target == targetfreq) return true;
        }
        return false;
    }
};
