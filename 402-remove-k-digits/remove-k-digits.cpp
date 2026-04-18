class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        if(n == k) return "0";
        stack<char>st;
        for(int i = 0 ; i < n ; i++){
            char curr = num[i];
            while(!st.empty() && st.top() > curr && k > 0){
                st.pop();
                k--;
            }
            st.push(curr);
        }

        while(k > 0){
            st.pop();
            k--;
        }

        string result = "";

        while(!st.empty()){
           result+= st.top();
           st.pop();
        }
        reverse(result.begin() , result.end());

        int i = 0;
        while(i < result.length() && result[i] == '0'){
            i++;
        }

        result = result.substr(i);

        return result == "" ? "0" : result;

    }
};