class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int len = s.length();
        vector<int> ans(len, 0);
        vector<int> indexCh;
        
        for (int i = 0; i < len; i++) {
            if (s[i] == c) {
                indexCh.push_back(i);
            }
        }
        
        
        int pos = 0;
        for (int i = 0; i < len; i++) {
            int distance = abs(i - indexCh[pos]);
            if (i > indexCh[pos]) {
                if (pos + 1 < indexCh.size()) {
                    int nextDistance = abs(i - indexCh[pos + 1]);
                    if (distance > nextDistance) {
                        distance = nextDistance;
                        pos++;
                    }
                }
            }
            ans[i] = distance;
        }
        return ans;
    }
};



class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> ans(n);

        for (int i = 0, idx = -n; i < n; ++i) {
            if (s[i] == c) {
                idx = i;
            }
            ans[i] = i - idx;
        }

        for (int i = n - 1, idx = 2 * n; i >= 0; --i) {
            if (s[i] == c) {
                idx = i;
            }
            ans[i] = min(ans[i], idx - i);
        }
        return ans;
    }
};
