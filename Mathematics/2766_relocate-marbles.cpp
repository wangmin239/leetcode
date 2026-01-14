
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> positions(nums.begin(), nums.end());
        int n = moveFrom.size();

        for (int i = 0; i < n; i++) {
            positions.erase(moveFrom[i]);
            positions.insert(moveTo[i]);
        }
         
        int size = positions.size();
        vector<int> ans(size);
        int i = 0;
        for (int curPos : positions) {
            ans[i++] = curPos;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        vector<int> ans;
        unordered_map<int, bool> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = true;
        }

        for (int i = 0; i < moveFrom.size(); i++) {
            mp.erase(moveFrom[i]);
            mp[moveTo[i]] = true;
        }

        for (const auto& pair : mp) {
            ans.push_back(pair.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};




class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> positions(nums.begin(), nums.end());
        int n = moveFrom.size();

        for (int i = 0; i < n; i++) {
            positions.erase(moveFrom[i]);
            if (positions.count(moveTo[i]) == 0) {
                positions.insert(moveTo[i]);
            }   
        }
         
        int size = positions.size();
        vector<int> ans(size);
        int i = 0;
        for (auto iter = positions.begin(); iter != positions.end(); ++iter) {
            ans[i++] = *iter;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};