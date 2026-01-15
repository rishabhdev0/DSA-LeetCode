class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {

        int n = recipes.size();
        vector<string> result;

        unordered_set<string> st(supplies.begin(), supplies.end());
        vector<bool> cooked(n, false);

        for (int round = 0; round < n; round++) {
            bool progress = false;

            for (int j = 0; j < n; j++) {
                if (cooked[j]) continue;

                bool banpaega = true;

                for (int k = 0; k < ingredients[j].size(); k++) {
                    if (!st.count(ingredients[j][k])) {
                        banpaega = false;
                        break;
                    }
                }

                if (banpaega) {
                    cooked[j] = true;
                    st.insert(recipes[j]);
                    result.push_back(recipes[j]);
                    progress = true;
                }
            }

            if (!progress) break;
        }

        return result;
    }
};
