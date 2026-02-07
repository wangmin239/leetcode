/* Official Solution 1 */
class Solution {
public:
    int minimumDeletions(string s) {
        int leftb = 0, righta = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') {
                righta++;
            }
        }
        int res = righta;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a') {
                righta--;
            } else {
                leftb++;
            }
            res = min(res, leftb + righta);
        }
        return res;
    }
};

/* Official Soluton 2 */
class Solution {
public:
    int minimumDeletions(string s) {
        int bCnt = 0, ans = 0;
        for (auto&& x : s) {
            if (x == 'a') ans = min(ans + 1, bCnt);
            else ++bCnt;
        }
        return ans;
    }
};