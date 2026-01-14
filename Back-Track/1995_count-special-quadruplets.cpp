class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size() - 3; i++) {
            ans += dfs(nums, i, 0, 0);
        }
        return ans;

    }
    
    int dfs(vector<int>& nums, int start, int sum, int cnt) {
        if (cnt == 4 || start == nums.size()) {
            return 0;
        }
        
        if (cnt == 3 && sum == nums[start]) {
            return 1;
        }
        int total = 0;
        for (int i = start; i < nums.size(); i++) {
            total += dfs(nums, i + 1, sum + nums[start], cnt + 1);           
        }
        return total;
    }
};

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int c = n - 2; c >= 2; --c) {
            ++cnt[nums[c + 1]];
            for (int a = 0; a < c; ++a) {
                for (int b = a + 1; b < c; ++b) {
                    if (int sum = nums[a] + nums[b] + nums[c]; cnt.count(sum)) {
                        ans += cnt[sum];
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int b = n - 3; b >= 1; --b) {
            for (int d = b + 2; d < n; ++d) {
                ++cnt[nums[d] - nums[b + 1]];
            }
            for (int a = 0; a < b; ++a) {
                if (int sum = nums[a] + nums[b]; cnt.count(sum)) {
                    ans += cnt[sum];
                }
            }
        }
        return ans;
    }
};




class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        for (int i = 0; i < len - 3; i++) {
            for (int j = i + 1; j < len - 2; j++) {
                for (int k = j + 1; k < len - 1; k++) {
                    for (int l = k + 1; l < len; l++) {
                        if (nums[i] + nums[j] + nums[k] == nums[l]) {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};