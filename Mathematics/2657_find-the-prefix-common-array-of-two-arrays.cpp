/* Original Solution 1 */
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> preA(n + 1, 0);
        vector<int> preB(n + 1, 0);
        vector<int> ans(n, n);

        ans[0] = A[0] == B[0];
        ++preA[A[0]];
        ++preB[B[0]];

        for (int i = 1; i < n; i++) {
            int a = A[i];
            int b = B[i];

            ++preA[a];
            ++preB[b];
            ans[i] = ans[i - 1];

            if (a == b) {
                ++ans[i];
                continue;
            }

            if (preA[b] != 0) {
                ++ans[i];
            }

            if (preB[a] != 0) {
                ++ans[i];
            }
        }

        return ans;
    }
};



/* Original Solution 2 */
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, n);
        unsigned long mask = 0;

        for (int i = n - 1; i > 0; i--) {
            mask |= 1UL << A[i];
            mask |= 1UL << B[i];
            ans[i - 1] = n - popcount(mask);

        }

        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        uint64_t p = 0, q = 0;
        for (int i = 0; i < A.size(); i++) {
            p |= 1ULL << A[i];
            q |= 1ULL << B[i];
            A[i] = popcount(p & q);
        }
        return A;
    }
};
