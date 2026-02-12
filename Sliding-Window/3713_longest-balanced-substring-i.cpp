/* Original Solution 1 */
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        const int alpha = 26;
        int ans = 0;
        auto check = [alpha](int* chArr) {
            int i;
            int cnt = 0;

            for (i = 0; i < alpha; i++) {
                if (chArr[i] != 0) {
                    cnt = chArr[i];
                    break;
                }
            }

            while (++i < alpha) {
                if (chArr[i] == 0) {
                    continue;
                }
                if (chArr[i] != cnt) {
                    return false;
                }
            }

            return true;
        };

        for (int i = 0; i < n; i++) {
            int chArr[alpha] = {0};
            for (int j = i; j < n; j++) {
                int id = s[j] - 'a';
                ++chArr[id];
                if (check(chArr) == true){
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};