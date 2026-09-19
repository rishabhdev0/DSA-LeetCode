class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // line sweep algorithm;
        vector<int>arr( n + 2 , 0);

        for(int i = 0 ; i < bookings.size() ; i++){
             int start = bookings[i][0];
             int end = bookings[i][1];
             int seat = bookings[i][2];
             arr[start] += seat;
             arr[end + 1] -= seat;
        }
        vector<int>result(n);
        int sum = 0;
        for(int i = 1 ; i <= n ; i++){
            sum += arr[i];
            result[i - 1] = sum;
        }
        return result;
    }
};