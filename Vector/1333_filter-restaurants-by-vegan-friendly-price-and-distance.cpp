class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        auto comp = [](const auto& lhs, const auto& rhs) {
            return lhs[1] == rhs[1]? lhs[0] > rhs[0] : lhs[1] > rhs[1];
        };
        
        sort(restaurants.begin(), restaurants.end(), comp);
        
        vector<int> ans;
        #define TRUE  1
        for (const auto& ele : restaurants) {
            if (ele[3] > maxPrice || ele.back() > maxDistance) {
                continue;
            }
            
            if (veganFriendly == TRUE && ele[2] != TRUE) {
                continue;
            }    
            ans.push_back(ele.front());
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int n = restaurants.size();
        vector<vector<int>> filtered;
        for (int i = 0; i < n; i++) {
            if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance && !(veganFriendly && !restaurants[i][2])) {
                filtered.push_back(restaurants[i]);
            }
        }
        sort(filtered.begin(), filtered.end(), [](vector<int> &v1, vector<int> &v2) -> bool {
            return v1[1] > v2[1] || (v1[1] == v2[1] && v1[0] > v2[0]);
        });
        vector<int> res;
        for (auto &v : filtered) {
            res.push_back(v[0]);
        }
        return res;
    }
};
