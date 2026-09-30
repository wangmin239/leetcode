/* Original Solution 1 */
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        unordered_map<int, vector<int>> leftParenthese;
        unordered_map<int, vector<int>> rightParenthese;
        int maxDepth = 0;
        int curDepth = 0;

        for (int i = 0; i < n; i++) {

            if (seq[i] == '(') {
                ++curDepth;
                leftParenthese[curDepth].push_back(i);
            } else {
                rightParenthese[curDepth].push_back(i);
                --curDepth;
            }

            maxDepth = max(maxDepth, curDepth);
        }

        int halfMax = maxDepth / 2;
        vector<int> ans(n, 0);
        curDepth = maxDepth;
        int depth = 0;

        auto setIndex = [&ans](int depth, unordered_map<int, vector<int>>& parenthese) {
                for (int index : parenthese[depth]) {
                    ans[index] = 1;
                }
        };

        for (curDepth = maxDepth; curDepth > halfMax; curDepth--) {
            setIndex(curDepth, leftParenthese);
            setIndex(curDepth, rightParenthese);
        }

        return ans;
    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int d = 0;
        vector<int> ans;
        for (char& c : seq)
            if (c == '(') {
                ++d;
                ans.push_back(d % 2);
            }
            else {
                ans.push_back(d % 2);
                --d;
            }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        for (int i = 0; i < (int)seq.size(); ++i) {
            ans.push_back(i & 1 ^ (seq[i] == '('));
        }
        return ans;
    }
};

