/* Original Solution 1 */
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        int mid = n / 2;
        
        for (int i = 0; i < mid; i++) {
            ans[i + mid] = i + 1;
            ans[i] = -ans[i + mid];
        }
        
        return ans;
    }
};


 /* Official Solution 1 */
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 == 1) {
            ans.push_back(0);
        }
        return ans;
    }
};
