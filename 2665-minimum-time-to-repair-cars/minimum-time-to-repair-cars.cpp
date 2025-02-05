// class Solution {
// private:
//     bool is_possible(vector<int>& ranks, int cars, long long min) {
//         long long car_done = 0;
//         for (auto r : ranks) {
//             car_done += floor(sqrt(min / r));  
//         }
//         return car_done >= cars;
//     }

// public:
//     long long repairCars(vector<int>& ranks, int cars) {
//         long long low = 1;
//         long long high = 1e14;
//         long long result = high; 
//         while (low <= high) {
//             long long mid = low + (high - low) / 2;
//             if (is_possible(ranks, cars, mid)) {
//                 result = mid;  
//                 high = mid - 1;  
//             } else {
//                 low = mid + 1;  
//             }
//         }

//         return result;  
//     }
// };
// class Solution{
//     public:
//     long long repairCars(vector<int>& ranks, int cars){
//         long long s=0;
//         long long e=1e14;
//         while(s<e){
//             long long mid=s+(e-s)/2;
//             int answer=0;
//             for(int i=0;i<ranks.size();i++){
//                 answer+=sqrt(mid/ranks[i]);
//             }
//             if(answer>=cars) e=mid;
//             else s=mid+1;
//         }
//         return s;
//     }
// };
#define ll long long
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long lo=0, hi=1e14;
        while( lo<hi ){
            ll mid=(lo+hi)/2;
            ll count=0;
            for(int i=0;i<ranks.size();i++){
                count+=sqrt(mid / ranks[i]);
            }
            if(count>=cars) hi=mid;
            else  lo=mid+1;
        }
        return lo;
    }
};