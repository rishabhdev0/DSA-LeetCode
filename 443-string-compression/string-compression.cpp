class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0; 
        int j = 0;   

        while (j < n) {
            char currentChar = chars[j]; 
            int count = 0;              

            while (j < n && chars[j] == currentChar) {
                j++;
                count++;
            }

            chars[index] = currentChar;
            index++;

            if (count > 1) {
                string countStr = to_string(count);
                for (char ch : countStr) {
                    chars[index] = ch;
                    index++;
                }
            }
        }

        return index; 
    }
};