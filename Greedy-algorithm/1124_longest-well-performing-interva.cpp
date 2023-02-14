class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> s(n + 1);
        stack<int> stk;
        stk.push(0);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if (s[stk.top()] > s[i]) {
                stk.push(i);
            }
        }

        int res = 0;
        for (int r = n; r >= 1; r--) {
            while (stk.size() && s[stk.top()] < s[r]) {
                res = max(res, r - stk.top());
                stk.pop();
            }
        }
        return res;
    }
};

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int, int> ump;
        int s = 0, res = 0;
        for (int i = 0; i < n; i++) {
            s += hours[i] > 8 ? 1 : -1;
            if (s > 0) {
                res = max(res, i + 1);
            } else {
                if (ump.count(s - 1)) {
                    res = max(res, i - ump[s - 1]);
                }
            }
            if (!ump.count(s)) {
                ump[s] = i;
            }
        }
        return res;
    }
};



class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> preSum(n + 1, 0);
        const int limit = 8;
        for (int i = 0; i < n; i++) {
            int val = hours[i] > limit ? 1 : -1;
            preSum[i + 1] = preSum[i] + val;
        }
        int ans = 0;
        for (int left = 0; left < n; left++) {
            int right = n;
            
            while (right > left) {
                if (preSum[right] - preSum[left] > 0) {
                    break;
                }
                right--;
            }
            ans = max(ans, right - left);
        }
        
        return ans;
    }
};