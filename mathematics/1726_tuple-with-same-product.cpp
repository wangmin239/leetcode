class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> multiResult;
        int n = nums.size();
        int cnt = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
           for (int j = i + 1; j < n; j++) {
                int multiVal = nums[i] * nums[j];
                ++multiResult[multiVal];
           }
        }
        auto sum = [](int count) {
            int sum = count * (count - 1) / 2;
            return 8 * sum;
        };
        for (auto [_, count] : multiResult) {
            if (count > 1) {
                cnt += sum(count);
            }
        }
        
        return cnt;
    }
};


class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                cnt[nums[i] * nums[j]]++;
            }
        }
        for (auto &[k, v] : cnt) {
            ans += v * (v - 1) * 4;
        }
        return ans;
    }
};
