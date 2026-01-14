class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        while (nums[0] > 0) {
            vector<int> cnt(10);
            for (int i = 0; i < n; i++) {
                cnt[nums[i] % 10]++;
                nums[i] /= 10;
            }
            for (int i = 0; i < 10; i++) {
                res += (long long) (n - cnt[i]) * cnt[i];
            }
        }
        return res / 2;
    }
};




class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        unordered_map<string, int> digits;
        
        for (int value : nums) {
            string num(to_string(value));
            ++digits[num];
        }
        
        long long sum = 0;
        auto getDiffCnt = [] (const string& lhs, const string& rhs) {
                int len = lhs.length();
                int cnt = 0;
               
                for (int i = 0; i < len; i++) {
                    cnt += static_cast<int>(lhs[i] != rhs[i]);
                }
                return cnt;
        };

        for (auto iter = digits.begin(); iter != digits.end(); ++iter) {
            auto nextIter = iter;
            for (++nextIter; nextIter != digits.end(); ++nextIter) {
                 sum += getDiffCnt(iter->first, nextIter->first) * iter->second * nextIter->second;
            }
        }
        
        return sum;
    }
};