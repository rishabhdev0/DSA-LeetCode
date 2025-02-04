class Solution {
private:
    int find_max(const vector<int>& weights) {
        int maxi = INT_MIN;
        for (int weight : weights) {
            maxi = max(weight, maxi);
        }
        return maxi;
    }
   int find_sum(const vector<int>&  weights){
    int totalweight=0;
    for(int weight:weights){
     totalweight+=weight;
    }
    return totalweight;
   }

int binarysearch(vector<int>& weights,int capacity,int days){
int load=0;
int day=1;
for(int weight:weights){
    load+=weight;
    if(load>capacity){
        day++;
        load=weight;
    }
    if(days<day){
        return 0;
    }
} 
return 1;
}

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int s=find_max(weights);
        int e=find_sum(weights);
        int result=e;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(binarysearch(weights,mid,days)){
                result=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
          return result ;
    }
};