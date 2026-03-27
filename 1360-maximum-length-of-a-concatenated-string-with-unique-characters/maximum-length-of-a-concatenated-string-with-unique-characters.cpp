class Solution {
public:

    bool is_unique(string &s1, string &s2) {
        int freq[26] = {0};

        for(char ch : s1) {
            freq[ch - 'a']++;
        }

        for(char ch : s2) {
            if(freq[ch - 'a'] > 0) return false;
            freq[ch - 'a']++;
        }

        return true;
    }

    int solve(vector<string>& arr, string temp, int idx) {
        if(idx == arr.size()) {
            return temp.length();
        }

        int take = 0;

        if(is_unique(temp, arr[idx])) {
            take = solve(arr, temp + arr[idx], idx + 1);
        }

        int not_take = solve(arr, temp, idx + 1);

        return max(take, not_take);
    }

    int maxLength(vector<string>& arr) {
        return solve(arr, "", 0);
    }
};