/* Official Solution 1 */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int top = -1; // 栈顶下标（把 nums 当作栈）
        for (int x : nums) {
            while (top >= 0 && x < nums[top]) {
                top--; // 出栈
                ans++;
            }
            // 如果 x 与栈顶相同，那么 x 与栈顶可以在同一次操作中都变成 0，x 无需入栈
            if (top < 0 || x != nums[top]) {
                nums[++top] = x; // 入栈
            }
        }
        return ans + top + (nums[0] > 0);
    }
};


/* Original Solution 1 */
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ops = 0;
        stack<int> ascendSt;
        /* initialize the first element as zero */
        ascendSt.push(0);
        for (int num : nums) {
            while (ascendSt.top() > num) {
                ascendSt.pop();
            } 
            if (ascendSt.top() < num) {
                ascendSt.push(num);
                ++ops;
            }
        }  
        
       return ops;
    }
};