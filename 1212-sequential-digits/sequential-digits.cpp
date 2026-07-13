class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s= "123456789";
        vector<int>result;
        int low_size = to_string(low).size();
        int high_size = to_string(high).size();

        for(int i =  low_size ; i <= high_size ; i++){
            for(int j = 0 ; j + i <= 9 ; j++){
                int num = stoi(s.substr(j , i));
                if(num >= low && num <= high){
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};