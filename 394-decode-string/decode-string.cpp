class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currString = "";
        int num = 0;
        
        for(char ch : s){
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }else if(ch == '['){
                countStack.push(num);  
                stringStack.push(currString); 
                // reset for the encoded section
                num = 0;
                currString = "";
            }else if(ch == ']'){
                string decoded = stringStack.top();
                stringStack.pop();
                int count = countStack.top();
                countStack.pop();
                for(int i = 0 ; i < count ; i++){
                    decoded += currString;
                }
                currString = decoded;  
            }else {
                currString += ch;
            }
        }
        return currString;  
    }
};