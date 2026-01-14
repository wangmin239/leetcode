/* Official Solution 1 */
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size(), n = m / 3;

        priority_queue<int, vector<int>, greater<>> min_pq(nums.end() - n, nums.end());
        long long sum = reduce(nums.end() - n, nums.end(), 0LL);

        vector<long long> suf_max(m - n + 1); // 后缀最大和
        suf_max[m - n] = sum;
        for (int i = m - n - 1; i >= n; i--) {
            int v = nums[i];
            if (v > min_pq.top()) {
                sum += v - min_pq.top();
                min_pq.pop();
                min_pq.push(v);
            }
            suf_max[i] = sum;
        }

        priority_queue<int> max_pq(nums.begin(), nums.begin() + n);
        long long pre_min = reduce(nums.begin(), nums.begin() + n, 0LL); // 前缀最小和

        long long ans = pre_min - suf_max[n]; // i=n-1 时的答案
        for (int i = n; i < m - n; i++) {
            int v = nums[i];
            if (v < max_pq.top()) {
                pre_min += v - max_pq.top();
                max_pq.pop();
                max_pq.push(v);
            }
            ans = min(ans, pre_min - suf_max[i + 1]);
        }
        return ans;
    }
};



/* Official Solution 2 */
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n3 = nums.size(), n = n3 / 3;
        vector<long long> part1(n + 1);
        long long sum = 0;
        // 大根堆
        priority_queue<int> ql;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
        }
        part1[0] = sum;
        for (int i = n; i < n * 2; ++i) {
            sum += nums[i];
            ql.push(nums[i]);
            sum -= ql.top();
            ql.pop();
            part1[i - (n - 1)] = sum;
        }
        
        long long part2 = 0;
        // 小根堆
        priority_queue<int, vector<int>, greater<int>> qr;
        for (int i = n * 3 - 1; i >= n * 2; --i) {
            part2 += nums[i];
            qr.push(nums[i]);
        }
        long long ans = part1[n] - part2;
        for (int i = n * 2 - 1; i >= n; --i) {
            part2 += nums[i];
            qr.push(nums[i]);
            part2 -= qr.top();
            qr.pop();
            ans = min(ans, part1[i - n] - part2);
        }
        return ans;
    }
};
