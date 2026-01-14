class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long sum = 0;
        const int divide = 3;
        for (int i = 0; i < k; i++) {
            int val = pq.top();
            pq.pop();
            pq.push(ceil(static_cast<double>(val) / divide));
            sum += val;
        }
        return sum;
    }
};


class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        long long ans = 0;
        for (int _ = 0; _ < k; ++_) {
            int x = q.top();
            q.pop();
            ans += x;
            q.push((x + 2) / 3);
        }
        return ans;
    }
};
