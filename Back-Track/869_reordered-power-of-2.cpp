class Solution {
    vector<int> vis;

    bool isPowerOfTwo(int n) {
        return (n & (n - 1)) == 0;
    }

    bool backtrack(string &nums, int idx, int num) {
        if (idx == nums.length()) {
            return isPowerOfTwo(num);
        }
        for (int i = 0; i < nums.length(); ++i) {
            // 不能有前导零
            if ((num == 0 && nums[i] == '0') || vis[i] || (i > 0 && !vis[i - 1] && nums[i] == nums[i - 1])) {
                continue;
            }
            vis[i] = 1;
            if (backtrack(nums, idx + 1, num * 10 + nums[i] - '0')) {
                return true;
            }
            vis[i] = 0;
        }
        return false;
    }

public:
    bool reorderedPowerOf2(int n) {
        string nums = to_string(n);
        sort(nums.begin(), nums.end());
        vis.resize(nums.length());
        return backtrack(nums, 0, 0);
    }
};



string countDigits(int n) {
    string cnt(10, 0);
    while (n) {
        ++cnt[n % 10];
        n /= 10;
    }
    return cnt;
}

unordered_set<string> powerOf2Digits;

int init = []() {
    for (int n = 1; n <= 1e9; n <<= 1) {
        powerOf2Digits.insert(countDigits(n));
    }
    return 0;
}();

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        return powerOf2Digits.count(countDigits(n));
    }
};
