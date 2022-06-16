class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), y = 0, res = 0;
        for (int x = 0; x < n; x++) {
            if (x == 0 || nums[x] != nums[x - 1]) {
                while (y < n && (nums[y] < nums[x] + k || y <= x)) {
                    y++;
                }
                if (y < n && nums[y] == nums[x] + k) {
                    res++;
                }
            }
        }
        return res;
    }
};




class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> visited;
        unordered_set<int> res;
        for (int num : nums) {
            if (visited.count(num - k)) {
                res.emplace(num - k);
            }
            if (visited.count(num + k)) {
                res.emplace(num);
            }
            visited.emplace(num);
        }
        return res.size();
    }
};

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> dataPair;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            dataPair[nums[i]].push_back(i);

        }
        
        auto getCnt = [](int val, int index, unordered_map<int, vector<int>>& pairsMap) {
            if (pairsMap.count(val) == 0) {
                return 0;
            }
            
            auto vec = pairsMap[val];
            int len = vec.size();
            int cnt = 0;
            for (int i = 0; i < len; i++) {
                if (vec[i] > index) {
                    cnt = 1;
                    break;
                }
            }
            
            return cnt;
        };
        
        int ans = 0;
        if (k == 0) {
            for (const auto [_, vec] : dataPair) {
                if (vec.size() > 1) {
                    ans++;
                }
            }
            return ans;
        }
        
        for (int i = 0; i < len; i++) {
            int num = nums[i];
            ans += getCnt(num + k, i, dataPair) + getCnt(num - k, i, dataPair);
        }
        
        return ans;
    }
};