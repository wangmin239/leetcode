/* Official Solution 1 */
class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> len(n);
        for (int i = n - 1, j = m - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            len[i] = m - j - 1;
        }
        vector<int> ans(m);
        bool valid = true;
        int j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            } else if (valid && (i == n - 1 || len[i + 1] >= m - j - 1)) {
                ans[j] = i;
                j++;
                valid = false;
            }
        }
        if (j < m) return {};
        return ans;
    }
};
