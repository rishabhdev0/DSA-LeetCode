class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        
        // Count frequency of each character using proper for loop
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            freq[ch - 'a']++;
            // Check if any character frequency exceeds the limit
            if(freq[ch - 'a'] > (n + 1) / 2) {
                return "";
            }
        }
        
        // Create max heap using priority queue (frequency, character)
        priority_queue<pair<int, char>> max_heap;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                max_heap.push({freq[i], 'a' + i});
            }
        }
        
        string result = "";
        
        while(max_heap.size() > 1) {
            // Get top 2 most frequent characters
            auto first = max_heap.top(); max_heap.pop();
            auto second = max_heap.top(); max_heap.pop();
            
            // Add them to result alternately
            result += first.second;
            result += second.second;
            
            // Decrease frequencies and push back if needed
            first.first--;
            second.first--;
            
            if(first.first > 0) {
                max_heap.push(first);
            }
            if(second.first > 0) {
                max_heap.push(second);
            }
        }
        
        // Handle the case when only one character is left
        if(!max_heap.empty()) {
            auto last = max_heap.top();
            result += last.second;
        }
        
        return result;
    }
};