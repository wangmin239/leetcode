/* Original Solution 1 */
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();
        long long start;
        vector<long long > timeStamp(n + 1, 0);


        for (int potion= 0; potion < m; potion++) {
            start = timeStamp[1];
            long long totalTime = 0;
            for (int wizard = 1; wizard < n; wizard++) {
                int timeSpec = skill[wizard - 1] * mana[potion];
                totalTime += timeSpec;
                timeStamp[wizard] = timeSpec;

                /* The current wizard hasn't finished brewing hist potion assigned to him in the previous turn. */
                if (start + totalTime < timeStamp[wizard + 1]) {
                    start = timeStamp[wizard + 1] - totalTime;
                }
            }

            /* Update the timeStamp */
            timeStamp[0] = start;
            for (int wizard = 1; wizard < n; wizard++) {
                start += timeStamp[wizard];
                timeStamp[wizard] = start;
            }
            timeStamp.back() = start + skill[n - 1] * mana[potion];

        }
        return timeStamp.back();

    }
};


/* Official Solution 1 */
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        vector<long long> last_finish(n); // 第 i 名巫师完成上一瓶药水的时间
        for (int m : mana) {
            // 按题意模拟
            long long sum_t = 0;
            for (int i = 0; i < n; i++) {
                sum_t = max(sum_t, last_finish[i]) + skill[i] * m;
            }
            // 倒推：如果酿造药水的过程中没有停顿，那么 lastFinish[i] 应该是多少
            last_finish[n - 1] = sum_t;
            for (int i = n - 2; i >= 0; i--) {
                last_finish[i] = last_finish[i + 1] - skill[i + 1] * m;
            }
        }
        return last_finish[n - 1];
    }
};


/* Official Solution 2 */
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<int> s(n + 1); // skill 的前缀和
        partial_sum(skill.begin(), skill.end(), s.begin() + 1);

        long long start = 0;
        for (int j = 1; j < m; j++) {
            long long mx = 0;
            for (int i = 0; i < n; i++) {
                mx = max(mx, 1LL * mana[j - 1] * s[i + 1] - 1LL * mana[j] * s[i]);
            }
            start += mx;
        }
        return start + 1LL * mana[m - 1] * s[n];
    }
};

/* Official Solution 3 */
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<int> s(n + 1);
        partial_sum(skill.begin(), skill.end(), s.begin() + 1);

        vector<int> suf = {n - 1};
        for (int i = n - 2; i >= 0; i--) {
            if (skill[i] > skill[suf.back()]) {
                suf.push_back(i);
            }
        }

        vector<int> pre = {0};
        for (int i = 1; i < n; i++) {
            if (skill[i] > skill[pre.back()]) {
                pre.push_back(i);
            }
        }

        long long start = 0;
        for (int j = 1; j < m; j++) {
            auto& record = mana[j - 1] < mana[j] ? pre : suf;
            long long mx = 0;
            for (int i : record) {
                mx = max(mx, 1LL * mana[j - 1] * s[i + 1] - 1LL * mana[j] * s[i]);
            }
            start += mx;
        }
        return start + 1LL * mana[m - 1] * s[n];
    }
};


/* Official Solution 4 */
struct Vec {
    int x, y;
    Vec operator-(const Vec& b) { return {x - b.x, y - b.y}; }
    long long det(const Vec& b) { return 1LL * x * b.y - 1LL * y * b.x; }
    long long dot(const Vec& b) { return 1LL * x * b.x + 1LL * y * b.y; }
};

class Solution {
    // Andrew 算法，计算 points 的上凸包
    // 由于横坐标（前缀和）是严格递增的，所以无需排序
    vector<Vec> convex_hull(vector<Vec>& points) {
        vector<Vec> q;
        for (auto& p : points) {
            while (q.size() > 1 && (q.back() - q[q.size() - 2]).det(p - q.back()) >= 0) {
                q.pop_back();
            }
            q.push_back(p);
        }
        return q;
    }

public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<int> s(n + 1);
        vector<Vec> vs(n);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + skill[i];
            vs[i] = {s[i], skill[i]};
        }
        vs = convex_hull(vs); // 去掉无用数据

        long long start = 0;
        for (int j = 1; j < m; j++) {
            Vec p = {mana[j - 1] - mana[j], mana[j - 1]};
            // p.dot(vs[i]) 是个单峰函数，二分找最大值
            int l = -1, r = vs.size() - 1;
            while (l + 1 < r) {
                int mid = l + (r - l) / 2;
                (p.dot(vs[mid]) > p.dot(vs[mid + 1]) ? r : l) = mid;
            }
            start += p.dot(vs[r]);
        }
        return start + 1LL * mana[m - 1] * s[n];
    }
};


/* Official Solution 5 */
class Solution {
public:
    using ll = long long;
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<ll> times(n);
        for (int j = 0; j < m; j++) {
            ll cur_time = 0;
            for (int i = 0; i < n; i++) {
                cur_time = max(cur_time, times[i]) + skill[i] * mana[j];
            }
            times[n - 1] = cur_time;
            for (int i = n - 2; i >= 0; i--) {
                times[i] = times[i + 1] - skill[i + 1] * mana[j];
            }
        }
        return times[n - 1];
    }
};
