class Solution {
public:
    int countBeautifulPairs(vector<int> &nums) {
        const int decimal = 10;
        int res = 0, cnt[decimal]{};
        for (int x: nums) {
            for (int y = 1; y < decimal; y++) {
                if (gcd(x % decimal, y) == 1) {
                    res += cnt[y];
                }
            }
            while (x >= decimal) {
                x /= decimal;
            }
            cnt[x]++;
        }
        return res;
    }
};




class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0;

        function<int(int)> getFirstDigit = [] (int val) {
            const int decimal = 10;
            while (val >= decimal) {
                val /= decimal;
            }
            return val;
        };

        for (int i = 0; i < size; i++) {
            int firstDigit = getFirstDigit(nums[i]);
            for (int j = i + 1; j < size; j++) {
                if (gcd(firstDigit, nums[j] % 10) == 1) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0;
        const int decimal = 10;

        function<int(int)> getFirstDigit = [&] (const int val) {

            if (val < decimal) {
                return val;
            }
            return getFirstDigit(val / decimal);
        };

        for (int i = 0; i < size; i++) {
            int firstDigit = getFirstDigit(nums[i]);
            for (int j = i + 1; j < size; j++) {
                if (gcd(firstDigit, nums[j] % decimal) == 1) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int size = nums.size();
        int cnt = 0;
        const int decimal = 10;

        auto getFirstDigit = [decimal] (const int val, auto&& dfs) {
            if (val < decimal) {
                return val;
            }
            return dfs(val / decimal, dfs);
        };

        for (int i = 0; i < size; i++) {
            int firstDigit = getFirstDigit(nums[i], getFirstDigit);
            for (int j = i + 1; j < size; j++) {
                if (gcd(firstDigit, nums[j] % decimal) == 1) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};