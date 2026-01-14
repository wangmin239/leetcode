class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.begin(), cards.end());
        
        int ans = 0;
        int tmp = 0;
        int odd, even = -1;
        int end = cards.size() - cnt;
        for (int i = cards.size() - 1; i >= end; i--) {
            tmp += cards[i];
            if (cards[i] & 1) {
                odd = cards[i];
            } else {
                even = cards[i];
            }
        }

        if (!(tmp & 1)) {
            return tmp;
        }

        for (int i = cards.size() - cnt - 1; i >= 0; i--) {
            if (cards[i] & 1) {
                if (even != -1) {
                    ans = max(ans, tmp - even + cards[i]);
                }
            } else {
                if (odd != -1) {
                    ans = max(ans, tmp - odd + cards[i]);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        int val[1005];
        for (int i = 0; i < cards.size(); i++) {
            val[cards[i]]++;
        }

        int ans = 0;
        int tmp = 0;
        int ed = -1;
        int odd, even = -1;
        for (int i = 1000; i >= 1; i--) {
            if (val[i] == 0) {
                continue;
            }

            if (val[i] > cnt) {
                tmp += cnt * i;
                cnt = 0;
            } else {
                tmp += val[i] * i;
                cnt -= val[i];
                val[i] = 0;
            }

            if (i & 1) {
                odd = i;
            } else {
                even = i;
            }

            if (!cnt) {
                if (val[i] > 0) {
                    ed = i;
                } else {
                    ed = i - 1;
                }
                break;
            }
        }

        if (!(tmp & 1)) {
            return tmp;
        }

        for (int i = ed; i >= 1; i--) {
            if (val[i] == 0) {
                continue;
            }

            if (i & 1) {
                if (even != -1) {
                    ans = max(ans, tmp - even + i);
                }
            } else {
                if (odd != -1) {
                    ans = max(ans, tmp - odd + i);
                }
            }
        }

        return ans;
    }
};





class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        int n = cards.size();

        auto dfs = [&](int index, int remain, auto&& innerDfs, int sum) {
            int ans = 0;
            if (remain == 0) {
                if (sum % 2 == 0) {
                    return sum;
                }
                return 0;
            }
            
            for (int i = index + 1; i < n; i++) {
               ans = max(ans, innerDfs(i, remain - 1, innerDfs, sum + cards[i]));
            }
            
            return ans;
        };
        
        int maxEvenSum = 0;
        for (int i = 0; i < n - cnt + 1; i++) {
            maxEvenSum = max(maxEvenSum, dfs(i, cnt - 1, dfs, cards[i]));
        }
        
        return maxEvenSum;
    }
};