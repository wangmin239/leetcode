class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string smallest = s;
            int n = s.size();
            for (int i = 1; i < n; i++) {
                char c = s[0];
                s = s.substr(1);
                s.push_back(c);
                if (s < smallest) {
                    smallest = s;
                }
            }
            return smallest;
        } else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            s += s;
            string_view sv(s), ans(sv);
            for (size_t i = 0, n = s.size() / 2; i < n; i++)
                ans = min(ans, sv.substr(i, n));
            return { ans.cbegin(),ans.cend() };
        }
        else {
            sort(s.begin(), s.end());
            return s;
        }
    }
};