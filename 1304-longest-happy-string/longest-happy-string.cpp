class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result;
        
        // Max heap to store pairs of (count, character)
        priority_queue<pair<int, char>> max_heap;
        
        // Push available characters into heap
        if (a > 0) max_heap.push({a, 'a'});
        if (b > 0) max_heap.push({b, 'b'});
        if (c > 0) max_heap.push({c, 'c'});
        
        while (!max_heap.empty()) {
            // Get the character with highest frequency
            auto [count1, char1] = max_heap.top();
            max_heap.pop();
            
            // Check if adding this character would create 3 consecutive same chars
            int n = result.size();
            if (n >= 2 && result[n-1] == char1 && result[n-2] == char1) {
                // If so, we need to use the second most frequent character
                if (max_heap.empty()) break;
                
                auto [count2, char2] = max_heap.top();
                max_heap.pop();
                
                result += char2;
                count2--;
                
                // Push back the second character if count > 0
                if (count2 > 0) max_heap.push({count2, char2});
                
                // Push back the first character
                max_heap.push({count1, char1});
            } else {
                // Safe to use the most frequent character
                result += char1;
                count1--;
                
                // Push back if count > 0
                if (count1 > 0) max_heap.push({count1, char1});
            }
        }
        
        return result;
    }
};