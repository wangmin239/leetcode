/* Original  Solution */
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
       unordered_map<int, int> digitMap;
       int rows = 0;
       
       for (int num : nums) {
           ++digitMap[num];
           rows = max(rows, digitMap[num]);
       }
       
       vector<vector<int>> matrix(rows);
       /* build a two dimension matrix */
       for (int row = 0; row < rows; row++) {
           for (auto& [value, cnt] : digitMap){
               if (cnt > 0) {
                    matrix[row].push_back(value);
                    --cnt;
               }
           }
        }
        
        return matrix;
    }
};


/* Official Solution */
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int x : nums) {
            cnt[x]++;
        }

        vector<vector<int>> ans;
        while (!cnt.empty()) {
            vector<int> arr;
            for (auto it = cnt.begin(); it != cnt.end(); ) {
                it->second -= 1;
                arr.emplace_back(it->first);
                if (it->second == 0) {
                    it = cnt.erase(it);
                } else {
                    it++;
                }
            }
            ans.push_back(arr);
        }
        
        return ans;
    }
};
