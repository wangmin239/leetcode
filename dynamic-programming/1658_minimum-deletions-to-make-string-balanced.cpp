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


class Solution {
public:
    int minimumDeletions(string s) {
        int a = 0, b = 0, n = s.size();
        for (auto&& x : s) {
            if (x == 'a') a += 1;
            else b = max(a, b) + 1;
        }
        return n - max(a, b);
    }
};
