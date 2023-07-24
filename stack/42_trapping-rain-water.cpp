class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};



class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> stk;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) {
                    break;
                }
                int left = stk.top();
                int currWidth = i - left - 1;
                int currHeight = min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stk.push(i);
        }
        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        stack<int> st;
        int left = 0;
        
        /* check if the current height is higher than the left  */
        for (const auto& val : height) {         
            while (!st.empty() && val >= left) {
                sum += left - st.top();
                st.pop();
            }
            if (st.empty()) {
                left = val;
            }
            st.push(val);

        }
        /* in the case that stack is not empty */
        int right = st.top();
        while (!st.empty()) {
            if (st.top() < right) {
                sum += right - st.top();
            } else {
                right = st.top();
            }
            st.pop();
        }
        
        return sum;
    }
};




class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        stack<int> st;
        int left = 0;
        
        for (const auto& val : height) {
            if (st.empty() == true) {
                left = val;
                st.push(val);
                continue;
            }
            
            if (val < left) {
                st.push(val);
                continue;
            }
            
            while (!st.empty()) {
                sum += left - st.top();
                st.pop();
            }
            left = val;
            st.push(val);

        }
        int right = st.top();
        while (!st.empty()) {
            if (st.top() < right) {
                sum += right - st.top();
            } else {
                right = st.top();
            }
            st.pop();
        }
        
        return sum;
    }
};