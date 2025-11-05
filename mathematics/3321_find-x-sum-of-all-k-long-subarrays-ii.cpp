/* Official Solution 1 */
class Helper {
public:
    Helper(int x) {
        this->x = x;
        this->result = 0;
    }

    void insert(int num) {
        if (occ[num]) {
            internalRemove({occ[num], num});
        }
        ++occ[num];
        internalInsert({occ[num], num});
    }

    void remove(int num) {
        internalRemove({occ[num], num});
        --occ[num];
        if (occ[num]) {
            internalInsert({occ[num], num});
        }
    }

    long long get() {
        return result;
    }

private:
    void internalInsert(const pair<int, int>& p) {
        if (large.size() < x || p > *large.begin()) {
            result += static_cast<long long>(p.first) * p.second;
            large.insert(p);
            if (large.size() > x) {
                result -= static_cast<long long>(large.begin()->first) * large.begin()->second;
                auto transfer = *large.begin();
                large.erase(transfer);
                small.insert(transfer);
            }
        }
        else {
            small.insert(p);
        }
    }

    void internalRemove(const pair<int, int>& p) {
        if (p >= *large.begin()) {
            result -= static_cast<long long>(p.first) * p.second;
            large.erase(p);
            if (!small.empty()) {
                result += static_cast<long long>(small.rbegin()->first) * small.rbegin()->second;
                auto transfer = *small.rbegin();
                small.erase(transfer);
                large.insert(transfer);
            }
        }
        else {
            small.erase(p);
        }
    }

private:
    int x;
    long long result;
    set<pair<int, int>> large, small;
    unordered_map<int, int> occ;
};

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        Helper helper(x);

        vector<long long> ans;
        for (int i = 0; i < nums.size(); ++i) {
            helper.insert(nums[i]);
            if (i >= k) {
                helper.remove(nums[i - k]);
            }
            if (i >= k - 1) {
                ans.push_back(helper.get());
            }
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        using pii = pair<int, int>; // 出现次数，元素值
        set<pii> L, R;
        long long sum_l = 0; // L 的元素和
        unordered_map<int, int> cnt;
        auto add = [&](int x) {
            pii p = {cnt[x], x};
            if (p.first == 0) {
                return;
            }
            if (!L.empty() && p > *L.begin()) { // p 比 L 中最小的还大
                sum_l += (long long) p.first * p.second;
                L.insert(p);
            } else {
                R.insert(p);
            }
        };
        auto del = [&](int x) {
            pii p = {cnt[x], x};
            if (p.first == 0) {
                return;
            }
            auto it = L.find(p);
            if (it != L.end()) {
                sum_l -= (long long) p.first * p.second;
                L.erase(it);
            } else {
                R.erase(p);
            }
        };
        auto l2r = [&]() {
            pii p = *L.begin();
            sum_l -= (long long) p.first * p.second;
            L.erase(p);
            R.insert(p);
        };
        auto r2l = [&]() {
            pii p = *R.rbegin();
            sum_l += (long long) p.first * p.second;
            R.erase(p);
            L.insert(p);
        };

        vector<long long> ans(nums.size() - k + 1);
        for (int r = 0; r < nums.size(); r++) {
            // 添加 in
            int in = nums[r];
            del(in);
            cnt[in]++;
            add(in);

            int l = r + 1 - k;
            if (l < 0) {
                continue;
            }

            // 维护大小
            while (!R.empty() && L.size() < x) {
                r2l();
            }
            while (L.size() > x) {
                l2r();
            }
            ans[l] = sum_l;

            // 移除 out
            int out = nums[l];
            del(out);
            cnt[out]--;
            add(out);
        }
        return ans;
    }
};
