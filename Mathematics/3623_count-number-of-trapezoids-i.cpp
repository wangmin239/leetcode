/* Original Solution 1 */
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1e9 + 7;
        const int divisor = 2;
        vector<int> levelPoints;
        int left, right;
        long long ans = 0LL;
        long long sum = 0LL;        
        /* Compare the values with respect to the Y-axis */
        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs.back() < rhs.back();
        };

        sort(points.begin(), points.end(), cmp);

        /* Calculate the point pairs located at the same horizontal level */
        for (left = 0, right = 0; right < points.size(); right++) {
            if (points[left].back() != points[right].back()) {
                int num = right - left;

                num = 1LL * num * (num - 1) / 2;
                levelPoints.push_back(num);
                left = right;
            }   
        }

        /* push the last pair into a vector */
        levelPoints.push_back(1LL *(right - left) * (right - left - 1) / 2);


        sum = reduce(levelPoints.begin(), levelPoints.end(), 0LL);
        for (size_t j = 0; j < levelPoints.size() - 1; j++) {
            sum -= levelPoints[j];
            ans += 1LL * levelPoints[j] * sum;
            ans %= mod;
        }


        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int MOD = 1'000'000'007;
        unordered_map<int, int> cnt;
        for (auto& p : points) {
            cnt[p[1]]++; // 统计每一行（水平线）有多少个点
        }

        long long ans = 0, s = 0;
        for (auto& [_, c] : cnt) {
            long long k = 1LL * c * (c - 1) / 2;
            ans += s * k;
            s += k;
        }
        return ans % MOD;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> pointNum;
        const int mod = 1e9 + 7;
        long long ans = 0, sum = 0;
        for (auto& point : points) {
            ++pointNum[point[1]];
        }
        for (auto& [_, pNum] : pointNum) {
            long long edge = 1LL * pNum * (pNum - 1) / 2;
            ans += edge * sum;
            sum += edge;
        }
        return ans % mod;
    }
};

/* Original Solution 2 */
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1e9 + 7;
        const int divisor = 2;
        vector<int> levelPoints;
        int left, right;
        long long ans = 0LL;
        long long sum = 0LL;        
        /* Compare the values with respect to the Y-axis */
        auto cmp = [](const auto& lhs, const auto& rhs) {
            return lhs.back() < rhs.back();
        };

        sort(points.begin(), points.end(), cmp);

        /* Calculate the point pairs located at the same horizontal level */
        for (left = 0, right = 0; right < points.size(); right++) {
            if (points[left].back() != points[right].back()) {
                int num = right - left;

                num = 1LL * num * (num - 1) / 2;
                levelPoints.push_back(num);
                left = right;
            }   
        }

        /* push the last pair into a vector */
        levelPoints.push_back(1LL * (right - left) * (right - left - 1) / 2);

        for (size_t j = 0; j < levelPoints.size(); j++) {
            ans += 1LL * levelPoints[j] * sum;
            ans %= mod;
            sum += levelPoints[j];
        }


        return ans;
    }
};