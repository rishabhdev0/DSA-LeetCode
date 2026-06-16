class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;

        for (int x : answers) {
            freq[x]++;
        }

        int count = 0;

        for (auto it : freq) {
            int num = it.first;      
            int time = it.second;    

            int groupSize = num + 1;

            int groups = (time + groupSize - 1) / groupSize; 
            count += groups * groupSize;
        }

        return count;
    }
};