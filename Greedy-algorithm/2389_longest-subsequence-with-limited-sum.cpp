class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int> f(n + 1);
        for (int i = 0; i < n; i++) {
            f[i + 1] = f[i] + nums[i];
        }
        vector<int> answer(m);
        for (int i = 0; i < m; i++) {
            answer[i] = upper_bound(f.begin(), f.end(), queries[i]) - f.begin() - 1;
        }
        return answer;
    }
};


class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        int n = nums.size();
        
        sort(nums.begin(), nums.end(), less<int>());
        int sum = 0;
        for (int& num : nums) {
            sum += num;
            num = sum;
        }

        auto getMaxLen = [&nums](int val) {
            auto pos = upper_bound(nums.begin(), nums.end(), val);
            return static_cast<int>(pos - nums.begin());
        };
        vector<int> answer(m);
        for (int i = 0; i < m; i++) {
            answer[i] = getMaxLen(queries[i]);
        }
        return answer;
    }
};