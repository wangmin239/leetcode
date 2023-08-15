class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int  len = blocks.length();
        int ans = 0;
        
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                ans++;
            }
        }
        int cnt = ans;
        for (int left = 1, right = k; left < len - k; left++, right++) {
            if (blocks[left - 1] == 'W') {
                --cnt;
            }
            if (blocks[right] == 'W') {
                ++cnt;
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0, cnt = 0;
        while (r < k) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            r++;
        }
        int res = cnt;
        while (r < blocks.size()) {
            cnt += blocks[r] == 'W' ? 1 : 0;
            cnt -= blocks[l] == 'W' ? 1 : 0;
            res = min(res, cnt);
            l++;
            r++;
        }
        return res;
    }
};


class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        string::size_type  len = blocks.length();
        int ans = INT_MAX;
        
        for (string::size_type i = 0; i < len - k + 1; i++) {
            int whiteCnt = 0;
            for (string::size_type j = 0; j < k; j++) {
                if (blocks[i + j] == 'W') {
                    whiteCnt++;
                }
            }
            ans = min(ans, whiteCnt);
        }
        return ans;
    }
};