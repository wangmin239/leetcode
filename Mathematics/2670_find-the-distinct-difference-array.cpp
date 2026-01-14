class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        vector<int> sufCnt(n + 1, 0);
        for (int i = n - 1; i > 0; i--) {
            st.insert(nums[i]);
            sufCnt[i] = st.size();
        }
        vector<int> res;
        st.clear();
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
            res.push_back(int(st.size()) - sufCnt[i + 1]);
        }
        return res;
    }
};



class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> cntFront(n), cntBack(n);
        unordered_map<int, int> front, back;
        
        for (int i = 0; i < n; i++) {
            ++front[nums[i]]];
            cntFront[i] = front.size();
            cntBack[n - i - 1] = back.size();
            ++back[nums[n - i - 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = cntFront[i] - cntBack[i];
        }

        return diffs;
    }
};


class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> diffs(n, 0);

        
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> front, back;
            for (int j = 0; j <= i; j++) {
                ++front[nums[j]];
            }
            
            for (int j = i + 1; j < n; j++) {
                ++back[nums[j]];
            }
            
            diffs[i] = front.size() - back.size();
        }
        

        return diffs;
    }
};


