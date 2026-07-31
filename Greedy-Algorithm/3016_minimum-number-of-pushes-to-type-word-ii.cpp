/* Original Solution 1 */
class Solution {
public:
    int minimumPushes(string word) {
        int minPressCnt = 0;
        int len = word.length();
        int curDigit = 0;
        const int digitNum = 8;
        const int chNum = 26;
        int chArr[chNum] = {0};

        for (char ch : word) {
            ++chArr[ch - 'a'];
        }

        sort(chArr, chArr + chNum, greater<int>());

        for (int chCnt : chArr){
            if (chCnt > 0) {
                int step = curDigit++ / digitNum + 1;
                minPressCnt += step * chCnt;

            } else {
                break;
            }
        }
        return minPressCnt;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for (char c : word) {
            ++freq[c - 'a'];
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26 && freq[i] > 0; ++i) {
            ans += (i / 8 + 1) * freq[i];
        }
        return ans;
    }
};
