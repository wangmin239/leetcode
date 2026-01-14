class SuffixArray {
public:
    using size_type = unsigned;
    using pointer = size_type*;
    using const_pointer = const size_type*;
    const_pointer sa, rk, ht;

private:
    std::unique_ptr<size_type[]> data;

private:
    template<typename S>
    inline static bool substring_equal(const S& s, size_type p1, size_type p2, size_type len) {
        for (size_type i = 0;i < len;++i)
            if (s[p1 + i] != s[p2 + i])
                return false;
        return true;
    }

    template<typename S>
    inline static void induced_sort(
        const S& s,
        pointer sa,
        bool* type,
        pointer pos,
        pointer lbuk,
        pointer sbuk,
        size_type n,
        size_type m,
        size_type n0) {
        std::fill_n(sa, n, 0);
        lbuk[0] = 0;
        for (size_type i = 1;i < m;++i)
            lbuk[i] = sbuk[i - 1];
        for (size_type i = n0;i-- > 0;)
            sa[--sbuk[s[pos[i]]]] = pos[i];
        sbuk[m - 1] = n;
        for (size_type i = 1;i < m;++i)
            sbuk[i - 1] = lbuk[i];
        sa[lbuk[s[n - 1]]++] = n - 1;
        for (size_type i = 0;i < n;++i)
            if (sa[i] > 0 && !type[sa[i] - 1])
                sa[lbuk[s[sa[i] - 1]]++] = sa[i] - 1;
        lbuk[0] = 0;
        for (size_type i = 1;i < m;++i)
            lbuk[i] = sbuk[i - 1];
        for (size_type i = n;i-- > 0;)
            if (sa[i] > 0 && type[sa[i] - 1])
                sa[--sbuk[s[sa[i] - 1]]] = sa[i] - 1;
    }

    template<typename S>
    inline static void sais(
        const S& s,
        pointer sa,
        bool* type,
        pointer len,
        pointer pos,
        pointer lbuk,
        pointer sbuk,
        size_type n,
        size_type m) {
        type[n - 1] = false;
        for (size_type i = n - 1;i-- > 0;)
            type[i] = s[i] != s[i + 1] ? s[i] < s[i + 1] : type[i + 1];
        size_type n0 = 0;
        for (size_type i = 1;i < n;++i)
            if (!type[i - 1] && type[i])
                pos[n0++] = i;
        std::fill_n(len, n, 0);
        for (size_type p = n - 1, i = n0;i-- > 0;p = pos[i])
            len[pos[i]] = p - pos[i] + 1;
        std::fill_n(sbuk, m, 0);
        for (size_type i = 0;i < n;++i)
            ++sbuk[s[i]];
        for (size_type i = 1;i < m;++i)
            sbuk[i] += sbuk[i - 1];
        induced_sort(s, sa, type, pos, lbuk, sbuk, n, m, n0);
        sbuk[m - 1] = n;
        for (size_type i = 1;i < m;++i)
            sbuk[i - 1] = lbuk[i];
        size_type m0 = -1;
        size_type ppos = -1, plen = 0;
        for (size_type i = 0;i < n;++i) {
            if (len[sa[i]] == 0) continue;
            if (len[sa[i]] != plen || !substring_equal(s, sa[i], ppos, plen)) ++m0;
            plen = len[sa[i]];
            len[sa[i]] = m0;
            ppos = sa[i];
        }
        pointer s0 = sa;
        pointer sa0 = sa + n0;
        for (size_type i = 0;i < n0;++i)
            s0[i] = len[pos[i]];
        if (++m0 < n0)
            sais(s0, sa0, type + n, len, pos + n0, lbuk, lbuk + n0, n0, m0);
        else for (size_type i = 0;i < n0;++i)
            sa0[s0[i]] = i;
        for (size_type i = 0;i < n0;++i)
            pos[i + n0] = pos[sa0[i]];
        induced_sort(s, sa, type, pos + n0, lbuk, sbuk, n, m, n0);
    }

public:
    template<typename S>
    SuffixArray(const S& s, size_type n, size_type m)
        : data(std::make_unique<size_type[]>(3 * n)) {
        const auto type = std::make_unique<bool[]>(2 * n);
        const auto lbuk = std::make_unique<size_type[]>(std::max(n, m));
        const auto sbuk = std::make_unique<size_type[]>(m);
        pointer sa = data.get(), rk = sa + n, ht = rk + n;
        sais(s, sa, type.get(), rk, ht, lbuk.get(), sbuk.get(), n, m);
        for (size_type i = 0;i < n;++i)
            rk[sa[i]] = i;
        for (size_type k = 0, i = 0;i < n;++i) {
            if (rk[i] == 0) continue;
            if (k > 0) --k;
            for (size_type j = sa[rk[i] - 1], l = n - std::max(i, j);k < l;++k)
                if (s[i + k] != s[j + k]) break;
            ht[rk[i]] = k;
        }
        this->sa = sa;
        this->rk = rk;
        this->ht = ht;
    }

    size_type suffix(size_type p) const {
        return sa[p];
    }

    size_type rank(size_type p) const {
        return rk[p];
    }

    size_type height(size_type p) const {
        return ht[p];
    }
};

class Solution {
public:
    string longestDupSubstring(string s) {
        const int n = s.size();
        SuffixArray sa(s, n, 128);
        int len = 0, pos = -1;
        for (int i = 1;i < n;++i) {
            if (sa.ht[i] > len) {
                len = sa.ht[i];
                pos = sa.sa[i];
            }
        }
        return pos == -1 ? "" : s.substr(pos, len);
    }
};




typedef pair<long long, long long> pll;
class Solution {
public:
    long long pow(int a, int m, int mod) {
        long long ans = 1;
        long long contribute = a;
        while (m > 0) {
            if (m % 2 == 1) {
                ans = ans * contribute % mod;
                if (ans < 0) {
                    ans += mod;
                }
            }
            contribute = contribute * contribute % mod;
            if (contribute < 0) {
                contribute += mod;
            }
            m /= 2;
        }
        return ans;
    }

    int check(const vector<int> & arr, int m, int a1, int a2, int mod1, int mod2) {
        int n = arr.size();
        long long aL1 = pow(a1, m, mod1);
        long long aL2 = pow(a2, m, mod2);
        long long h1 = 0, h2 = 0;
        for (int i = 0; i < m; ++i) {
            h1 = (h1 * a1 % mod1 + arr[i]) % mod1;
            h2 = (h2 * a2 % mod2 + arr[i]) % mod2;
            if (h1 < 0) {
                h1 += mod1;
            }
            if (h2 < 0) {
                h2 += mod2;
            }
        }
        // 存储一个编码组合是否出现过
        set<pll> seen;
        seen.emplace(h1, h2);
        for (int start = 1; start <= n - m; ++start) {
            h1 = (h1 * a1 % mod1 - arr[start - 1] * aL1 % mod1 + arr[start + m - 1]) % mod1;
            h2 = (h2 * a2 % mod2 - arr[start - 1] * aL2 % mod2 + arr[start + m - 1]) % mod2;
            if (h1 < 0) {
                h1 += mod1;
            }
            if (h2 < 0) {
                h2 += mod2;
            }

            // 如果重复，则返回重复串的起点
            if (seen.count(make_pair(h1, h2))) {
                return start;
            }
            seen.emplace(h1, h2);
        }
        // 没有重复，则返回-1
        return -1;
    }

    string longestDupSubstring(string s) {
        srand((unsigned)time(NULL));
        // 生成两个进制
        int a1 = random()%75 + 26;
        int a2 = random()%75 + 26;

        // 生成两个模
        int mod1 = random()%(INT_MAX - 1000000006) + 1000000006;
        int mod2 = random()%(INT_MAX - 1000000006) + 1000000006;
        int n = s.size();
        // 先对所有字符进行编码
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = s[i] - 'a';
        }
        // 二分查找的范围是[1, n-1]
        int l = 1, r = n - 1;
        int length = 0, start = -1;
        while (l <= r) {
            int m = l + (r - l + 1) / 2;
            int idx = check(arr, m, a1, a2, mod1, mod2);
            if (idx != -1) {
                // 有重复子串，移动左边界
                l = m + 1;
                length = m;
                start = idx;
            } else {
                // 无重复子串，移动右边界
                r = m - 1;
            }
        }
        return start != -1 ? s.substr(start, length) : "";
    }
};

class Solution {
public:
    string longestDupSubstring(string s) {
        const uint64_t b = 97755331;
        int l = 0, n = s.size(), r = n - 1, pos = 0;
        auto check = [&](int x){
            uint64_t h = 0, p = 1;
            for(int i = 0; i < x; ++i) h = h * b + s[i], p *= b;
            unordered_set<uint64_t> ss{h};
            for(int i = x; i < n; ++i) {
                h = h * b - p * s[i-x] + s[i];
                if(ss.count(h)) return i;
                ss.insert(h);
            }
            return 0;
        };
        while(l < r){
            int m = (l + r + 1) >> 1, ret;
            (ret = check(m)) ? l = m : r = m - 1;
            ret ? pos = ret : pos;
        }
        return s.substr(pos - l + 1, l);
    }
};
