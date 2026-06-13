/* Official Solution 1 */
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans(n, 'z');
        const int mod = 26;
        int i = 0;

        for (const string word : words) {
            int sum = 0;

            for (char ch : word) {
                int index = ch - 'a';

                sum  += weights[index];
                sum %= mod;
            }

            ans[i++] -= sum;
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        ans.reserve(words.size());
        for (string word : words) {
            int s = 0;
            for (char c : word) {
                s += weights[c - 'a'];
            }
            ans += 'z' - s % 26;
        }
        return ans;
    }
};
