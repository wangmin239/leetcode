/* Official Solution 1 */
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        const long long NEG_INF = LLONG_MIN / 2; // 除 2 防止下面加法（和负数相加）溢出
        long long ans = NEG_INF, f1 = NEG_INF, f2 = NEG_INF, f3 = NEG_INF;
        for (int i = 1; i < nums.size(); i++) {
            long long x = nums[i - 1], y = nums[i];
            f3 = x < y ? max(f3, f2) + y : NEG_INF;
            f2 = x > y ? max(f2, f1) + y : NEG_INF;
            f1 = x < y ? max(f1, x) + y : NEG_INF;
            ans = max(ans, f3);
        }
        return ans;
    }
};

/* Official Solution 2 */
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        for (int i = 0; i < n;) {
            // 第一段
            int start = i;
            for (i++; i < n && nums[i - 1] < nums[i]; i++);
            if (i == start + 1) { // 第一段至少要有两个数
                continue;
            }

            // 第二段
            int peak = i - 1;
            long long res = nums[peak - 1] + nums[peak]; // 第一段的最后两个数必选
            for (; i < n && nums[i - 1] > nums[i]; i++) {
                res += nums[i]; // 第二段的所有元素必选
            }
            if (i == peak + 1 || i == n || nums[i - 1] == nums[i]) { // 第二段至少要有两个数，第三段至少要有两个数
                continue;
            }

            // 第三段
            int bottom = i - 1;
            res += nums[i]; // 第三段的前两个数必选（第一个数在上面的循环中加了）
            // 从第三段的第三个数往右，计算最大元素和
            long long max_s = 0, s = 0;
            for (i++; i < n && nums[i - 1] < nums[i]; i++) {
                s += nums[i];
                max_s = max(max_s, s);
            }
            res += max_s;

            // 从第一段的倒数第三个数往左，计算最大元素和
            max_s = 0; s = 0;
            for (int j = peak - 2; j >= start; j--) {
                s += nums[j];
                max_s = max(max_s, s);
            }
            res += max_s;
            ans = max(ans, res);

            i = bottom; // 第三段的起点也是下一个极大三段式子数组的第一段的起点
        }
        return ans;
    }
};


/* Official Solution 3 */
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int p, q, j;
        long long max_sum, sum, res;
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            j = i + 1;
            res = 0;
            //第一段
            for(; j < n && nums[j -1] < nums[j]; j++);
            p = j - 1;
            if (p == i) {
                continue;
            }
            //第二段
            res += nums[p] + nums[p - 1];
            for(; j < n && nums[j - 1] > nums[j]; j++){
                res += nums[j];
            }
            q = j - 1;
            if (q == p || q == n - 1 || (nums[j] <= nums[q])) {
                i = q;
                continue;
            }
            //第三段
            res += nums[q + 1];
            //第三段求累加最大值
            max_sum = 0;
            sum = 0;
            for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
            }
            res += max_sum;
            //第一段求累加最大值
            max_sum = 0;
            sum = 0;
            for (int k = p - 2; k >= i; k--) {
                sum += nums[k];
                max_sum = max(max_sum, sum);
            }
            res += max_sum;
            //更新答案
            ans = max(ans, res);
            i = q - 1;
        }
        return ans;
    }
};
