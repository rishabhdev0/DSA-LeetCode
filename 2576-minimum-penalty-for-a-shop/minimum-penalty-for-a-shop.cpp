class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        
        int penalty_Y = count(customers.begin(), customers.end(), 'Y');
        
        int min_penalty = penalty_Y; 
        int min_hour = 0;
        int current_penalty = penalty_Y;
        
        for(int i = 0; i < n; i++){
            if(customers[i] == 'Y'){
                current_penalty--; 
            } else 
                current_penalty++; 
            
            if(current_penalty < min_penalty){
                min_penalty = current_penalty;
                min_hour = i + 1;
            }
        }
        
        return min_hour;
    }
};