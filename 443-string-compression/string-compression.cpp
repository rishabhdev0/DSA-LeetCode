class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int j = 0; // to store the previos char
        int i = 0;   

        while (i < n) {
            char currentChar = chars[i]; 
            int count = 0;              

            while (i < n && chars[i] == currentChar) {
                i++;
                count++;
            }

            chars[j] = currentChar;
            j++;

            if (count > 1) {
                string countStr = to_string(count);
                for (char ch : countStr) {
                    chars[j] = ch;
                    j++;
                }
            }
        }

        return j; 
    }
};