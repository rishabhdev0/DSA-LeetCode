class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = accumulate(gas.begin(), gas.end(), 0);
        int totalSpend = accumulate(cost.begin(), cost.end(), 0);
        
        if(totalSpend > totalGas) return -1;
        
        int start = 0;
        int tank = 0;
        
        for(int i = 0; i < n; i++) {
            tank += gas[i] - cost[i];
            
            if(tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        
        return start;
    }
};