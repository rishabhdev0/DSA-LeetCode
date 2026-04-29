class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();

        sort(properties.begin(), properties.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        });

        int weak = 0;
        int maxDefense = 0;

        for(int i = 0; i < n; i++){
            int defense = properties[i][1];

            if(defense < maxDefense){
                weak++;
            }

            maxDefense = max(maxDefense, defense);
        }

        return weak;
    }
};