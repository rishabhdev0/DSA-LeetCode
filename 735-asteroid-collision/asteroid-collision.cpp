class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for(int a : asteroids) {
         
            while(!st.empty() && st.back() > 0 && a < 0) {
                int sum = st.back() + a;
                
                if(sum > 0) {       // Top wins
                    a=0;        
                } 
                else if(sum < 0) {  // Current wins
                    st.pop_back();  
                } 
                else {              // Both destroyed
                    st.pop_back();
                    a=0;
                }
            }
            
            if(a != 0) {  //if the asteroid didnt colloid
                st.push_back(a);
            }
        }
        
        return st;
    }
};