/* Official Solution 1 */
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        // 前缀和
        vector<long long> sum(n + 1);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + stations[i];
        }

        // 初始电量
        vector<long long> power(n);
        long long mn = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            power[i] = sum[min(i + r + 1, n)] - sum[max(i - r, 0)];
            mn = min(mn, power[i]);
        }

        auto check = [&](long long low) -> bool {
            vector<long long> diff(n + 1);
            long long sum_d = 0, built = 0;
            for (int i = 0; i < n; i++) {
                sum_d += diff[i]; // 累加差分值
                long long m = low - (power[i] + sum_d);
                if (m <= 0) {
                    continue;
                }
                // 需要在 i+r 额外建造 m 个供电站
                built += m;
                if (built > k) { // 不满足要求
                    return false;
                }
                // 把区间 [i, i+2r] 加一
                sum_d += m; // 由于 diff[i] 后面不会再访问，我们直接加到 sum_d 中
                diff[min(i + r * 2 + 1, n)] -= m;
            }
            return true;
        };

        // 开区间二分
        long long left = mn + k / n, right = mn + k + 1;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;
    }
};


/* Official Solution 2 */
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        // 滑动窗口
        // 先计算 [0, r-1] 的发电量，为第一个窗口做准备
        long long sum = reduce(stations.begin(), stations.begin() + r, 0LL);
        vector<long long> power(n);
        long long mn = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            // 右边进
            if (i + r < n) {
                sum += stations[i + r];
            }
            // 左边出
            if (i - r - 1 >= 0) {
                sum -= stations[i - r - 1];
            }
            power[i] = sum;
            mn = min(mn, sum);
        }

        auto check = [&](long long low) -> bool {
            vector<long long> diff(n + 1);
            long long sum_d = 0, built = 0;
            for (int i = 0; i < n; i++) {
                sum_d += diff[i]; // 累加差分值
                long long m = low - (power[i] + sum_d);
                if (m <= 0) {
                    continue;
                }
                // 需要在 i+r 额外建造 m 个供电站
                built += m;
                if (built > k) { // 不满足要求
                    return false;
                }
                // 把区间 [i, i+2r] 加一
                sum_d += m; // 由于 diff[i] 后面不会再访问，我们直接加到 sum_d 中
                diff[min(i + r * 2 + 1, n)] -= m;
            }
            return true;
        };

        // 开区间二分
        long long left = mn + k / n, right = mn + k + 1;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            (check(mid) ? left : right) = mid;
        }
        return left;
    }
};

/* Official Solution 3 */
class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            cnt[left] += stations[i];
            cnt[right] -= stations[i];
        }

        auto check = [&](long long val) -> bool {
            vector<long long> diff = cnt; 
            long long sum = 0;
            long long remaining = k;
            
            for (int i = 0; i < n; i++) {
                sum += diff[i];
                if (sum < val) {
                    long long add = val - sum;
                    if (remaining < add) {
                        return false;
                    }
                    remaining -= add;
                    int end = min(n, i + 2 * r + 1);
                    diff[end] -= add;
                    sum += add;
                }
            }
            return true;
        };

        long long lo = ranges::min(stations);
        long long hi = accumulate(stations.begin(), stations.end(), 0LL) + k;
        long long res = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (check(mid)) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return res;
    }
};
