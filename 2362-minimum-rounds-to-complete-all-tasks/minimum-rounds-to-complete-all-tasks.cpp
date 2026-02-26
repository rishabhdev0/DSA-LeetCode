class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int , int>freq;
        for(int task : tasks){
            freq[task]++;
        }
        int count = 0;
        for(auto it : freq){
            if(it.second < 2){
                return -1;
            }else{
                if(it.second % 3 == 0){
                    count+= it.second / 3;
                }else {
                    count += (it.second / 3) + 1;
                }
            }
        }
        return count;
    }
};