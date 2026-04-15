/* Original Solution 1 */
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = n;

        for (int i = startIndex; i < n + startIndex; i++) {
            if (words[i % n] == target) {
                ans = i - startIndex;
                break;
            }
        }

        for (int i = n + startIndex - 1; i > startIndex; i--) {
            if (words[i % n] == target) {
                ans = min(ans, n + startIndex - i);
                break;
            }
        }

        return ans == n ? -1 : ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = words.size();
        int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int dist = abs(i - startIndex);
                ans = min(ans, min(dist, n - dist));
            }
        }
        
        return ans < n ? ans : -1;
    }
};


/* Official Solution 2 */
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for (int k = 0; k <= n / 2; k++) {
            if (words[(startIndex - k + n) % n] == target || words[(startIndex + k) % n] == target) {
                return k;
            }
        }
        return -1;
    }
};
