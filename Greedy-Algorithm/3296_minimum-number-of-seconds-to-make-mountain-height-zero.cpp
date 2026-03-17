/* Original Solution 1 */
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxTime = *max_element(workerTimes.begin(), workerTimes.end());
        int n = workerTimes.size();
        auto getHeight = [mountainHeight](long long time, int work) {
            int right = mountainHeight;
            int left = 0;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long cur = 1LL * (1 + mid) * mid / 2 * work;

                if (cur > time) {
                    right = mid - 1;
                } else if (cur < time) {
                    left = mid + 1;
                } else {
                    return mid;
                }
            }
            return right;
        };

        long long right = 1LL * (1 + mountainHeight) * mountainHeight / 2 * maxTime;
        long long left = 0;
        long long ans = -1;
        vector<int> heights(n);

        while (left <= right) {
            int  curHeight = 0;
            long long mid = left + (right - left) / 2;


            for (int i = 0; i < n; i++) {
                heights[i] = getHeight(mid, workerTimes[i]);
                curHeight += heights[i];
            }

            if (curHeight < mountainHeight) {
                left = mid + 1;
            } else if (curHeight > mountainHeight) {
                right = mid - 1;
            } else {
                ans = mid;
                break;
            }
        }

        if (ans == -1) {
            return left;
        }

        long long minTime = 0;
        for (int i = 0; i < n; i++) {
            minTime = max(minTime, 1LL * workerTimes[i] * (1 + heights[i]) * heights[i] / 2);
        }
        return minTime;
    }
};



/* Official Solution 1 */
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int maxWorkerTimes = *max_element(workerTimes.begin(), workerTimes.end());
        long long l = 1, r = static_cast<long long>(maxWorkerTimes) * mountainHeight * (mountainHeight + 1) / 2;
        long long ans = 0;

        while (l <= r) {
            long long mid = (l + r) / 2;
            long long cnt = 0;
            for (int t: workerTimes) {
                long long work = mid / t;
                // 求最大的 k 满足 1+2+...+k <= work
                long long k = (-1.0 + sqrt(1 + work * 8)) / 2 + eps;
                cnt += k;
            }
            if (cnt >= mountainHeight) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }

private:
    static constexpr double eps = 1e-7;
};


/* Official Solution 2 */
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<tuple<long long, long long, int>, vector<tuple<long long, long long, int>>, greater<>> pq;
        for (int t : workerTimes) {
            pq.emplace(t, t, t);
        }

        long long ans = 0;
        while (mountainHeight--) {
            // 工作后总用时，当前工作（山高度降低 1）用时，workerTimes[i]
            auto [total, cur, base] = pq.top(); pq.pop();
            ans = total; // 最后一个出堆的 total 即为答案
            pq.emplace(total + cur + base, cur + base, base);
        }
        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto check = [&](long long m) {
            int left_h = mountainHeight;
            for (int t : workerTimes) {
                left_h -= ((int) sqrt(m / t * 8 + 1) - 1) / 2;
                if (left_h <= 0) {
                    return true;
                }
            }
            return false;
        };

        int max_t = ranges::max(workerTimes);
        int h = (mountainHeight - 1) / workerTimes.size() + 1;
        long long left = 0, right = (long long) max_t * h * (h + 1) / 2;
        while (left + 1 < right) {
            long long mid = (left + right) / 2;
            (check(mid) ? right : left) = mid;
        }
        return right;
    }
};
