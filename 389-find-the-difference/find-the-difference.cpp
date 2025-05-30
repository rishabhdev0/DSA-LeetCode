class Solution {
public:
    char findTheDifference(string s, string t) {
        // using xor
        int XOR = 0; // a^a = 0;
        for(char &ch:s){
            XOR^= ch;
        }
        for(char &ch:t){
            XOR^=ch;
        }
        return (char)XOR; // conver xor in char then return 
    }
};