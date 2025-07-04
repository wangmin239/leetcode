/* Official Solution 1 */
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if (((long long)1 << t) == k) {
                t--;
            }
            k = k - ((long long)1 << t);
            if (operations[t]) {
                ans++;
            }
        }
        return 'a' + (ans % 26);
    }
};



/* Official Solution 2 */
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if (((long long)1 << t) == k) {
                t--;
            }
            k = k - ((long long)1 << t);
            if (operations[t]) {
                ans++;
            }
        }
        return 'a' + (ans % 26);
    }
};


/* Official Solution 3 */
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if (operations.empty()) {
            return 'a';
        }
        int op = operations.back();
        operations.pop_back();
        int n = operations.size(); // 注意这里是减一后的 n
        if (n >= 63 || k <= (1LL << n)) { // k 在左半边
            return kthCharacter(k, operations);
        }
        // k 在右半边
        char ans = kthCharacter(k - (1LL << n), operations);
        return 'a' + (ans - 'a' + op) % 26;
    }
};
