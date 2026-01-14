class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k]) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            res += i * (j - i) * (n - j);
        }
        return res;
    }
};





class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto x : nums) {
            count[x]++;
        }
        int res = 0, n = nums.size(), t = 0;
        for (auto [_, v] : count) {
            res += t * v * (n - t - v);
            t += v;
        }
        return res;
    }
};




class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    continue;
                }
                for (int k = j + 1; k < n; k++) {
                    if (nums[k] != nums[j] && nums[k] != nums[i]) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};

