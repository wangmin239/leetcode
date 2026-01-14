/* Original Solution 1 */
class Solution {
public:
    int dismantlingAction(string arr) {
        int len = arr.length();
        unordered_set<char> actions;
        int maxAction = 0;
        
        for (int left = 0, right = 0; right < len; right++) {
            char ch = arr[right];

            while (left < right && actions.count(ch) > 0) {
                char prevCh = arr[left++];
                actions.erase(prevCh);
            }
            actions.insert(ch);
            maxAction = max(maxAction, static_cast<int>(actions.size()));
        }
        
        return maxAction;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int dismantlingAction(string arr) {
        int n = arr.length(), ans = 0, left = 0;
        unordered_set<char> window; // 维护从下标 left 到下标 right 的字符
        for (int right = 0; right < n; ++right) {
            char c = arr[right];
            while (window.count(c)) // 加入 c 后，窗口内会有重复元素
                window.erase(arr[left++]);
            window.insert(c);
            ans = max(ans, right - left + 1); // 更新窗口长度最大值
        }
        return ans;
    }
};
