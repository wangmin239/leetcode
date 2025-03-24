
/* AI Solution 1 */
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false; // 奇数长度不可能有效
        
        int min_open = 0, max_open = 0;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') { // 不可变的情况
                if (s[i] == '(') {
                    min_open++;
                    max_open++;
                } else {
                    min_open--;
                    max_open--;
                }
            } else { // 可变的情况
                min_open--;
                max_open++;
                min_open = max(min_open, 0); // 确保min_open不小于0
            }
            
            if (max_open < 0) return false; // 无论怎么调整都无法满足
            min_open = max(min_open, 0); // 确保min_open不小于0
        }
        
        return (min_open <= 0 && 0 <= max_open);
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        int mx = 0;   // 可以达到的最大分数
        int mn = 0;   // 可以达到的最小分数 与 最小有效前缀对应分数 的较大值
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                // 此时对应字符无法更改
                int diff;
                if (s[i] == '(') {
                    diff = 1;
                }
                else {
                    diff = -1;
                }
                mx += diff;
                mn = max(mn + diff, (i + 1) % 2);
            }
            else {
                // 此时对应字符可以更改
                ++mx;
                mn = max(mn - 1, (i + 1) % 2);
            }
            if (mx < mn) {
                // 此时该前缀无法变为有效前缀
                return false;
            }
        }
        // 最终确定 s 能否通过变换使得分数为 0（成为有效字符串）
        return mn == 0;
    }
};

/* Official Solution 2 */
class Solution {
    public boolean canBeValid(String s, String locked) {
        int n = s.length();
        if(n % 2 != 0) return false; // 奇数长度不可能平衡

        int balance = 0;
        // 从左到右扫描，假设所有未锁定位置都能变为 '('
        for (int i = 0; i < n; i++) {
            if (locked.charAt(i) == '0' || s.charAt(i) == '(') {
                balance++;
            } else { // locked且为 ')'
                balance--;
            }
            if (balance < 0) return false;
        }

        balance = 0;
        // 从右到左扫描，假设所有未锁定位置都能变为 ')'
        for (int i = n - 1; i >= 0; i--) {
            if (locked.charAt(i) == '0' || s.charAt(i) == ')') {
                balance++;
            } else { // locked且为 '('
                balance--;
            }
            if (balance < 0) return false;
        }
        return true;
    }
}