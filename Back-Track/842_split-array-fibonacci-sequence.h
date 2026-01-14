class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        backTrace(S, res, 0, 0, 0);
        return res;
    }
    long getVal(const string& S, int start, int end) {
        long val = 0;
        while(start <= end) {
            val = 10 * val + S[start++] - '0';
        }
        return val;
    }
    bool backTrace(const string& S, vector<int>& res, int index, long sum, int prev) {
        /* satisfy the requirement */
        if (index == S.length() && res.size() > 2) {
            return true;
        }

        /* dfs */
        for (int i = index; i < S.length(); i++) {
            if (i > index && S[index] == '0') {
                break;
            }

            long cur = getVal(S, index, i);
            if (cur > INT_MAX) {
                break;
            }

            if (res.size() > 1) {
                if (cur < sum) {
                    continue;
                } else if (cur > sum) {
                    break;
                }
            }

            /* Fibonacci sequence */
            res.push_back(static_cast<int>(cur));
            if (backTrace(S, res, i + 1, prev + cur, cur) == true) {
                return true;
            }
            res.pop_back();
        }
        return false;
    }
};