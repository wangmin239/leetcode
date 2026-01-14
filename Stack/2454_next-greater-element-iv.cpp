class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> st;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.top().first < nums[i]) {
                res[q.top().second] = nums[i];
                q.pop();
            }
            while (!st.empty() && nums[st.top()] < nums[i]) {
                q.push({nums[st.top()], st.top()});
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};


class Solution {
public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        vector<int> st1;
        vector<int> st2;
        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            while (!st2.empty() && nums[st2.back()] < v) {
                res[st2.back()] = v;
                st2.pop_back();
            }
            int pos = st1.size() - 1;
            while (pos >= 0 && nums[st1[pos]] < v) {
                --pos;
            }
            st2.insert(st2.end(), st1.begin() + (pos + 1), st1.end());
            st1.resize(pos + 1);
            st1.push_back(i);
        }
        return res;
    }
};



class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    ++cnt;
                }
                if (cnt == 2) {
                    ans[i] = nums[j];
                    break;
                }
            }
        }
        return ans;
    }
};