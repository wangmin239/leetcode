/* Original Solution 1 */
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans(n, '0');
        auto increaseStr = [n](string& str) {
            int incr = 1;
            for (int i = n - 1; i >= 0; i--) {
                if (incr == 0) {
                    break;
                }
                int sum = str[i] - '0' + incr;
                incr = sum / 2;
                str[i] = '0' + sum % 2;
            }
        };

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            if (nums[i] != ans) {
                break;
            }
            increaseStr(ans);
        }

        return ans;
    }
};


/* Official Solution 1 */
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        // 预处理对应整数的哈希集合
        unordered_set<int> vals;
        for (const string& num : nums){
            vals.insert(stoi(num, nullptr, 2));
        }
        // 寻找第一个不在哈希集合中的整数
        int val = 0;
        while (vals.count(val)){
            ++val;
        }
        // 将整数转化为二进制字符串返回
        return bitset<16>(val).to_string().substr(16 - n, 16);
    }
};


/* Official Solution 2 */
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[i][i] ^ 1;
        }
        return ans;
    }
};
