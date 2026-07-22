/* Official Solution 1 */
class SegmentTree {
private:
    int n;
    vector<int> arr;
    vector<int> seg;

    void build(int p, int l, int r) {
        if (l == r) {
            seg[p] = arr[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        seg[p] = max(seg[p << 1], seg[p << 1 | 1]);
    }

    int _query(int p, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return seg[p];
        }

        int mid = (l + r) >> 1;
        int res = 0;
        if (L <= mid) {
            res = max(res, _query(p << 1, l, mid, L, R));
        }
        if (R > mid) {
            res = max(res, _query(p << 1 | 1, mid + 1, r, L, R));
        }

        return res;
    }

public:
    SegmentTree(const vector<int>& arr) : arr(arr) {
        n = arr.size();
        seg.resize(n << 2, 0);
        build(1, 0, n - 1);
    }

    int query(int L, int R) {
        if (L > R) {
            return 0;
        }

        return _query(1, 0, n - 1, L, R);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int cnt1 = count(s.begin(), s.end(), '1');

        vector<int> zeroBlocks;
        vector<int> blockLeft;
        vector<int> blockRight;

        int i = 0;
        while (i < n) {
            int st = i;
            while (i < n && s[i] == s[st]) {
                i += 1;
            }
            if (s[st] == '0') {
                zeroBlocks.push_back(i - st);
                blockLeft.push_back(st);
                blockRight.push_back(i - 1);
            }
        }

        int m = zeroBlocks.size();
        if (m < 2) {  // 连续 0 区块少于 2 段，直接返回答案
            return vector<int>(queries.size(), cnt1);
        }

        vector<int> tmpSum(m - 1);
        for (int i = 0; i < m - 1; i++) {
            tmpSum[i] = zeroBlocks[i] + zeroBlocks[i + 1];
        }
        SegmentTree seg(tmpSum);
        vector<int> ans;

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int i = lower_bound(blockRight.begin(), blockRight.end(), l) - blockRight.begin();
            int j = upper_bound(blockLeft.begin(), blockLeft.end(), r) - blockLeft.begin() - 1;

            // 子字符串内最多有 1 个 连续 0 区块
            if (i > m - 1 || j < 0 || i >= j) {
                ans.push_back(cnt1);
                continue;
            }
            int firstLen = blockRight[i] - max(blockLeft[i], l) + 1; // 子字符串的第一个连续 0 区块的实际长度
            int lastLen = min(blockRight[j], r) - blockLeft[j] + 1; // 子字符串的最后一个连续 0 区块的实际长度
            // 子字符串内恰好有 2 个连续 0 区块
            if (i + 1 == j) {
                int bestGain = firstLen + lastLen;
                ans.push_back(cnt1 + bestGain);
                continue;
            }

            int val1 = firstLen + zeroBlocks[i + 1];
            int val2 = zeroBlocks[j - 1] + lastLen;
            int val3 = seg.query(i + 1, j - 2);
            int bestGain = max({val1, val2, val3});
            ans.push_back(cnt1 + bestGain);
        }

        return ans;
    }
};


/* Official Solution 2 */
class SparseTable {
private:
    vector<vector<int>> st;

public:
    SparseTable(const vector<int>& data) {
        st.push_back(data);
        int i = 1, N = st[0].size();
        while (2 * i <= N + 1) {
            const auto& pre = st.back();
            vector<int> cur;
            for (int j = 0; j < N - 2 * i + 1; j++) {
                cur.push_back(max(pre[j], pre[j + i]));
            }
            st.push_back(cur);
            i <<= 1;
        }
    }

    int query(int begin, int end) {
        if (begin > end) {
            return 0;
        }
        int len = end - begin + 1;
        int lg = 0;
        while ((1 << (lg + 1)) <= len) {
            lg++;
        }
        return max(st[lg][begin], st[lg][end - (1 << lg) + 1]);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int cnt1 = count(s.begin(), s.end(), '1');

        vector<int> zeroBlocks;
        vector<int> blockLeft;
        vector<int> blockRight;

        int i = 0;
        while (i < n) {
            int st = i;
            while (i < n && s[i] == s[st]) {
                i += 1;
            }
            if (s[st] == '0') {
                zeroBlocks.push_back(i - st);
                blockLeft.push_back(st);
                blockRight.push_back(i - 1);
            }
        }

        int m = zeroBlocks.size();
        if (m < 2) {  // 连续 0 区块少于 2 段，直接返回答案
            return vector<int>(queries.size(), cnt1);
        }
        vector<int> tmpSum(m - 1);
        for (int i = 0; i < m - 1; i++) {
            tmpSum[i] = zeroBlocks[i] + zeroBlocks[i + 1];
        }
        SparseTable st(tmpSum);
        vector<int> ans;

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int i = lower_bound(blockRight.begin(), blockRight.end(), l) - blockRight.begin();
            int j = upper_bound(blockLeft.begin(), blockLeft.end(), r) - blockLeft.begin() - 1;

            // 子字符串内最多有 1 个 连续 0 区块
            if (i > m - 1 || j < 0 || i >= j) {
                ans.push_back(cnt1);
                continue;
            }
            
            int firstLen = blockRight[i] - max(blockLeft[i], l) + 1; // 子字符串的第一个连续 0 区块的实际长度
            int lastLen = min(blockRight[j], r) - blockLeft[j] + 1; // 子字符串的最后一个连续 0 区块的实际长度
            // 子字符串内恰好有 2 个连续 0 区块
            if (i + 1 == j) {
                int bestGain = firstLen + lastLen;
                ans.push_back(cnt1 + bestGain);
                continue;
            }

            int val1 = firstLen + zeroBlocks[i + 1];
            int val2 = zeroBlocks[j - 1] + lastLen;
            int val3 = st.query(i + 1, j - 2);
            int bestGain = max({val1, val2, val3});
            ans.push_back(cnt1 + bestGain);
        }

        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length(), m = queries.size();
        int cnt1 = count(s.begin(), s.end(), '1');
        // left[i]：表示以位置 i 结尾，与 s[i] 相同的连续区块长度
        vector<int> left(n, -1);
        // right[i]：表示以位置 i 开始，与 s[i] 相同的连续区块长度
        vector<int> right(n, -1);

        for (int i = 0; i < n; i++) {
            left[i] = (i > 0 && s[i-1] == s[i]) ? left[i-1] + 1 : 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            right[i] = (i < n-1 && s[i+1] == s[i]) ? right[i+1] + 1 : 1;
        }
        
        vector<int> ans(m, -1);
        int block_size = (int)sqrt(n);
        // 长度大于块长的询问
        vector<tuple<int, int, int, int>> longQueries;
        
        auto brute_force = [&](int l, int r) -> int {
            int i = l;
            int best = 0;
            int prev = INT_MIN;
            
            while (i <= r) {
                int start = i;
                while (i <= r && s[i] == s[start]) {
                    i++;
                }
                if (s[start] == '0') {
                    int cur = i - start;
                    best = (prev != INT_MIN && prev + cur > best) ? prev + cur : best;
                    prev = cur;
                }
            }
            return best;
        };
        
        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            if (r - l + 1 > block_size) {
                longQueries.push_back({l / block_size, l, r, i});
            } else {
                // 长度小于块长的询问，暴力计算
                ans[i] = cnt1 + brute_force(l, r);
            }
        }
        
        // 以询问左端点所在块的 ID 为第一关键字，询问右端点为第二关键字排序
        sort(longQueries.begin(), longQueries.end(), 
             [](const tuple<int,int,int,int>& a, const tuple<int,int,int,int>& b) {
                 if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
                 return get<2>(a) < get<2>(b);
             });
        
        deque<int> subZeroBlocks;
        int L = 0, R = 0, bestGain = 0;
        
        for (int i = 0; i < longQueries.size(); i++) {
            int bid = get<0>(longQueries[i]);
            int l = get<1>(longQueries[i]);
            int r = get<2>(longQueries[i]);
            int qid = get<3>(longQueries[i]);
            
            if (i == 0 || bid > get<0>(longQueries[i-1])) {
                // 遍历到一个新的块, 进行初始化操作
                L = (bid + 1) * block_size - 1;   // L 初始化为为该块右端点
                R = (bid + 1) * block_size;       // R 初始化为下一块左端点
                subZeroBlocks.clear();
                bestGain = 0;
            }
            
            while (R <= r) {
                int sz = min(r - R + 1, right[R]);
                if (s[R] == '0') {
                    if (!subZeroBlocks.empty() && s[R-1] == '0') {
                        subZeroBlocks.back() += sz;
                    } else {
                        subZeroBlocks.push_back(sz);
                    }
                    if (subZeroBlocks.size() >= 2) {
                        bestGain = max(subZeroBlocks.back() + subZeroBlocks[subZeroBlocks.size()-2], bestGain);
                    }
                }
                R += sz;
            }
            
            // 移动左端点 L 前，备份 bestGain 的值
            int tmp_bestGain = bestGain;
            // 移动左端点前，subZeroBlocks第一个元素（如果有）的值
            int tmp_firstValue = subZeroBlocks.empty() ? -1 : subZeroBlocks.front();
            // 记录移动左端点 L 的过程中，从左侧加入的数字数量
            int cnt = 0;
            
            while (L >= l) {
                int sz = min(L - l + 1, left[L]);
                if (s[L] == '0') {
                    if (!subZeroBlocks.empty() && s[L+1] == '0') {
                        subZeroBlocks.front() += sz;
                    } else {
                        subZeroBlocks.push_front(sz);
                        cnt++;
                    }
                    if (subZeroBlocks.size() >= 2) {
                        bestGain = max(subZeroBlocks[0] + subZeroBlocks[1], bestGain);
                    }
                }
                L -= sz;
            }
            
            // 回答询问
            ans[qid] = bestGain + cnt1;
            // 还原左端点 L
            L = (bid + 1) * block_size - 1;
            // 还原 bestGain
            bestGain = tmp_bestGain;
            // 还原 subZeroBlocks
            for (int j = 0; j < cnt; j++) {
                subZeroBlocks.pop_front();
            }
            if (tmp_firstValue != -1) {
                subZeroBlocks[0] = tmp_firstValue;
            }
        }
        return ans;
    }
};
