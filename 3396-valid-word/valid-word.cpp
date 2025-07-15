class Solution {
public:
    bool isValid(string word) {
       int n = word.size();
       if(n < 3) return false;
       bool vowel =  false;
       bool consonant = false;
       for(char ch : word){
          if(isalpha(ch)){
            ch =  tolower(ch);
            if(ch=='a' || ch=='e' || ch=='i' ||  ch=='o' || ch=='u'){
                vowel = true;
            }else consonant = true;
          }
         else if (!isdigit(ch)) return false;
       }
       return vowel && consonant;
    }
};