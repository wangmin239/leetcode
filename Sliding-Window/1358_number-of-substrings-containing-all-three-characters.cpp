/* Original Solution 1 */
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        const int chCnt = 3;
        int arr[chCnt] = {0};
        int sum = 0;
        auto check = [chCnt](int arr[chCnt]) {
            for (int i = 0; i < chCnt; i++) {
                if (arr[i] == 0) {
                    return false;
                }
            }
            return true;
        };

        for (int left = 0, right = 0; right < n; right++) {
            int index = s[right] - 'a';
            ++arr[index];

            if (check(arr) == false) {
                continue;
            }

            int cnt = 0;
            while (check(arr) == true) {
                index = s[left++] - 'a';
                --arr[index];
                ++cnt;
            }
            sum += cnt * (n - right);
        }
        return sum;
    }
};

/* Official Solution 1 */
class Solution { 
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int ans = 0;
        vector<vector<int>> pre(3, vector<int>(len + 1));
        pre[0][0] = pre[1][0] = pre[2][0] = 0;

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < 3; ++j) {
                pre[j][i + 1] = pre[j][i];
            }
            pre[s[i] - 'a'][i + 1]++;
        }
        
        for (int i = 0; i < len; ++i) {
            int left = i + 1, right = len, pos = -1;
            while (left <= right) {
                int mid = left + ((right - left) >> 1);
                if (pre[0][mid] - pre[0][i] > 0 && 
                    pre[1][mid] - pre[1][i] > 0 && 
                    pre[2][mid] - pre[2][i] > 0) {
                    right = mid - 1;
                    pos = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            if (pos != -1) {
                ans += len - pos + 1;
            }
        }
        
        return ans;
    }
};



/* Official Solution 2 */
class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        int ans = 0;
        vector<int> cnt(3);
        
        for (int l = 0, r = -1; l < len; ) {
            while (r < len && !(cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 1)) {
                r++;
                if (r == len) {
                    break;
                }
                cnt[s[r] - 'a']++;
            }
            if (r < len) {
                ans += len - r;
            }
            cnt[s[l] - 'a']--;
            l++;
        }
        
        return ans;
    }
};
