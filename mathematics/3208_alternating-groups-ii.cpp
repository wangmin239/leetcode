class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int cnt = 0;

        
        for (int begin = 0, end = 1; begin < n && end < n + k; ++end) {
            /* jump to the first index of meeting the requirements */
            if ((colors[(end - 1) % n] ^ colors[end % n ]) != 1) {
               begin = end;
               continue;
            }
            /* meet the requirements*/
            if (end - begin + 1== k) {
                ++cnt;
                ++begin;
            }
            
        }
        
        return cnt;
    }
};

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int res = 0, cnt = 1;
        for (int i = -k + 2; i < n; i++) {
            if (colors[(i + n) % n] != colors[(i - 1 + n) % n]) {
                cnt += 1;
            } else {
                cnt = 1;
            }
            if (cnt >= k) {
                res += 1;
            }
        }
        return res;
    }
};
