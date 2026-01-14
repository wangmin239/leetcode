class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(begin(properties), end(properties), [](const vector<int> & a, const vector<int> & b) {
            return a[0] == b[0] ? (a[1] > b[1]) : (a[0] < b[0]);
        });
        stack<int> st;
        int ans = 0;
        for (auto & p: properties) {
            while (!st.empty() && st.top() < p[1]) {
                ++ans;
                st.pop();
            }
            st.push(p[1]);
        }
        return ans;
    }
};


class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector<int> & a, const vector<int> & b) {
            return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]);
        });
        
        int maxDef = 0;
        int ans = 0;
        for (auto & p : properties) {
            if (p[1] < maxDef) {
                ans++;
            } else {
                maxDef = p[1];
            }
        }
        return ans;
    }
};
