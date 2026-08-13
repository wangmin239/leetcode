/* Official Solution 1 */
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        vector<int> pre(4 * n), suf(4 * n), maxLen(4 * n);
        vector<char> leftChar(4 * n), rightChar(4 * n);

        auto pushUp = [&](int u, int l, int r) {
            int mid = (l + r) >> 1;
            int leftLen = mid - l + 1, rightLen = r - mid;
            int left = u << 1, right = u << 1 | 1;
            leftChar[u] = leftChar[left];
            rightChar[u] = rightChar[right];
            pre[u] = pre[left];
            if (pre[left] == leftLen && rightChar[left] == leftChar[right]) {
                pre[u] = pre[left] + pre[right];
            }
            suf[u] = suf[right];
            if (suf[right] == rightLen && rightChar[left] == leftChar[right]) {
                suf[u] = suf[right] + suf[left];
            }
            maxLen[u] = max(maxLen[left], maxLen[right]);
            if (rightChar[left] == leftChar[right]) {
                maxLen[u] = max(maxLen[u], suf[left] + pre[right]);
            }
        };

        function<void(int, int, int)> build = [&](int u, int l, int r) {
            if (l == r) {
                pre[u] = 1;
                suf[u] = 1;
                maxLen[u] = 1;
                leftChar[u] = s[l];
                rightChar[u] = s[l];
                return;
            }
            int mid = (l + r) >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
            pushUp(u, l, r);
        };

        function<void(int, int, int, int, char)> update = [&](int u, int l, int r, int pos, char ch) {
            if (l == r) {
                leftChar[u] = ch;
                rightChar[u] = ch;
                return;
            }
            int mid = (l + r) >> 1;
            if (pos <= mid) {
                update(u << 1, l, mid, pos, ch);
            } else {
                update(u << 1 | 1, mid + 1, r, pos, ch);
            }
            pushUp(u, l, r);
        };

        build(1, 0, n - 1);
        int k = queryIndices.size();
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = maxLen[1];
        }
        return ans;
    }
};


/* Official Solution 2 */
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        set<pair<int, int>> segs;
        multiset<int> lens;

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            segs.insert({i, j - 1});
            lens.insert(j - i);
            i = j;
        }

        int k = queryIndices.size();
        vector<int> ans(k);

        for (int q = 0; q < k; q++) {
            int pos = queryIndices[q];
            char ch = queryCharacters[q];

            if (s[pos] != ch) {
                auto it = segs.upper_bound({pos, INT_MAX});
                --it;
                int L = it->first, R = it->second;
                segs.erase(it);
                lens.erase(lens.find(R - L + 1));

                if (L <= pos - 1) {
                    segs.insert({L, pos - 1});
                    lens.insert(pos - L);
                }
                if (pos + 1 <= R) {
                    segs.insert({pos + 1, R});
                    lens.insert(R - pos);
                }

                int newL = pos, newR = pos;

                auto rightIt = segs.lower_bound({pos + 1, 0});
                if (rightIt != segs.end() && rightIt->first == pos + 1 && s[pos + 1] == ch) {
                    lens.erase(lens.find(rightIt->second - rightIt->first + 1));
                    newR = rightIt->second;
                    segs.erase(rightIt);
                }

                auto leftIt = segs.lower_bound({pos, 0});
                if (leftIt != segs.begin()) {
                    --leftIt;
                    if (leftIt->second == pos - 1 && s[pos - 1] == ch) {
                        lens.erase(lens.find(leftIt->second - leftIt->first + 1));
                        newL = leftIt->first;
                        segs.erase(leftIt);
                    }
                }

                segs.insert({newL, newR});
                lens.insert(newR - newL + 1);
                s[pos] = ch;
            }

            ans[q] = *lens.rbegin();
        }

        return ans;
    }
};


/* Official Solution 3 */
struct Data {
    int mx, pre, suf;
};

// 详细注释见 https://leetcode.cn/circle/discuss/mOr1u6/
class SegmentTree {
    int n;
    string s;
    vector<Data> tree;

    void maintain(int node, int l, int m, int r) {
        Data& left = tree[node * 2];
        Data& right = tree[node * 2 + 1];
        int mx = max(left.mx, right.mx);
        int pre = left.pre;
        int suf = right.suf;
        if (s[m] == s[m + 1]) { // 左区间的最后一个字符 == 右区间的第一个字符
            mx = max(mx, left.suf + right.pre);
            if (left.pre == m - l + 1) {
                pre += right.pre;
            }
            if (right.suf == r - m) {
                suf += left.suf;
            }
        }
        tree[node] = {mx, pre, suf};
    }

    void build(int node, int l, int r) {
        if (l == r) { // 叶子
            tree[node] = {1, 1, 1}; // 初始化叶节点的值
            return;
        }
        int m = (l + r) >> 1;
        build(node * 2, l, m); // 初始化左子树
        build(node * 2 + 1, m + 1, r); // 初始化右子树
        maintain(node, l, m, r);
    }

    void update(int node, int l, int r, int i, char val) {
        if (l == r) { // 叶子（到达目标）
            s[i] = val;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m) { // i 在左子树
            update(node * 2, l, m, i, val);
        } else { // i 在右子树
            update(node * 2 + 1, m + 1, r, i, val);
        }
        maintain(node, l, m, r);
    }

public:
    SegmentTree(const string& s) : n(s.size()), s(s), tree(2 << bit_width(s.size() - 1)) {
        build(1, 0, n - 1);
    }

    void update(int i, char val) {
        update(1, 0, n - 1, i, val);
    }

    int query_all() const {
        return tree[1].mx;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree t(s);
        int q = queryIndices.size();
        vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            t.update(queryIndices[i], queryCharacters[i]);
            ans[i] = t.query_all();
        }
        return ans;
    }
};
