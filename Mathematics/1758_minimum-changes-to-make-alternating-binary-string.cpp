/* Original Solution 1 */
class Solution {
public:
    int minOperations(string s) {
        auto getStep = [&s](char startCh) {
           int step = 0;

           for (char ch : s) {
               if (ch != startCh) {
                   ++step;
               }
               startCh = '0' + !(startCh - '0');
            }
            return step;
        };

        return min(getStep('0'), getStep('1'));

    }
};


/* Official Solution 1 */
class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c != ('0' + i % 2)) {
                cnt++;
            }
        }
        return min(cnt, (int)s.size() - cnt);
    }
};
