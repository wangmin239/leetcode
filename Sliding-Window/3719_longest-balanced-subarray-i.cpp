/* Original Solutin 1 */
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> digits;
            int even = 0;
            int odd = 0;
            int j = i - 1;

            while (++j < n) {
                if (digits.count(nums[j]) > 0) {
                    if (even == odd) {
                        ans = max(ans, j - i + 1);
                    }
                    continue;
                }
                digits.insert(nums[j]);
                if (nums[j] & 0x1) {
                    ++odd;
                } else {
                    ++even;
                }

                if (even == odd) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

/* Official Solutin 1 */
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        size_t len = 0;

        for (size_t i = 0; i < nums.size(); i++) {
            auto odd = unordered_map<int, int>();
            auto even = unordered_map<int, int>();

            for (size_t j = i; j < nums.size(); j++) {
                auto& c = (nums[j] & 1) ? odd : even;
                c[nums[j]]++;

                if (odd.size() == even.size()) {
                    len = std::max(len, j - i + 1);
                }
            }
        }

        return int(len);
    }
};
