class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++) {
            d[i] = d[i - 1] + 2;
            if (i > 1 && word[i - 1] > word[i - 2]) {
                d[i] = d[i - 1] - 1;
            }
        }
        return d[n];
    }
};


class Solution {
public:
    int addMinimum(string word) {
        int n = word.size();
        int res = word[0] - word[n - 1] + 2;
        for (int i = 1; i < n; i++) {
            res += (word[i] - word[i - 1] + 2) % 3;
        }
        return res;
    }
};

class Solution {
public:
    int addMinimum(string word) {
        int n = word.size(), cnt = 1;
        for (int i = 1; i < n; i++) {
            if (word[i] <= word[i - 1]) {
                cnt++;
            }
        }
        return cnt * 3 - n;
    }
};
