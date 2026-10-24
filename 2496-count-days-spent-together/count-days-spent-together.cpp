class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

        int a = days[stoi(arriveAlice.substr(0, 2)) - 1] + stoi(arriveAlice.substr(3, 2));
        int b = days[stoi(leaveAlice.substr(0, 2)) - 1] + stoi(leaveAlice.substr(3, 2));
        int c = days[stoi(arriveBob.substr(0, 2)) - 1] + stoi(arriveBob.substr(3, 2));
        int d = days[stoi(leaveBob.substr(0, 2)) - 1] + stoi(leaveBob.substr(3, 2));

        int start = max(a, c);
        int end = min(b, d);

        if (start > end) return 0;

        return end - start + 1;
    }
};