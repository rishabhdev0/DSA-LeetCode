class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        
        for(int a : asteroids) {
         
            while(!st.empty() && st.back() > 0 && a < 0) {
                int sum = st.back() + a;
                
                if(sum > 0) {       // st.top() wins 
                    a=0;            // no need to push
                } 
                else if(sum < 0) {  // Current wins
                    st.pop_back();  // pop the element
                } 
                else {              // Both destroyed
                    st.pop_back();  // no need to  push and pop the element
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