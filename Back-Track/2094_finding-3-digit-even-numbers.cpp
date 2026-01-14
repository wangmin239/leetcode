/* Original Solution 1 */
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        const int limit = 10;
        int digitArr[limit] = {0};
        vector<int> ans;
        
        /* count the number of each digit */
        for (int digit : digits) {
            ++digitArr[digit];
        }
        
        function<void(int, int)> backTrace = [&](int num, int cnt) {
            /* exclude the values below the minimum */
            #define MIN 99 
            if (cnt == 3) {
                if (num > MIN) {
                    ans.push_back(num);
                }
                return ;
            }
            /* populate the units place of a three-digit number with an even number */
            if (cnt == 0) {
                for (int i = 0; i < limit; i++) {
                    if (digitArr[i] > 0 && ((i & 0x1) == 0)) {
                        --digitArr[i];
                        backTrace(num + 1 * pow(10, cnt) * i, cnt + 1);
                        ++digitArr[i];
                    }
                }
            } else {
                for (int i = 0; i < limit; i++) {
                    if (digitArr[i] > 0) {
                        --digitArr[i];
                        backTrace(num + 1 * pow(10, cnt) * i, cnt + 1);
                        ++digitArr[i];
                    }
                }
                
            }
        };  
        
        backTrace(0, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};


/* Original Solution 2 */
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        vector<bool> visited(n, false);
        unordered_set<int> nums;
        
        for (int i = 0; i < n; i++) {
            if (digits[i] & 0x1) {
                continue;
            }
            visited[i] = true;
            
            for (int j = 0; j < n; j++) {
                if (visited[j] == true) {
                    continue;
                }
                visited[j] = true;

                
                for (int k = 0; k < n; k++) {
                    if (visited[k] == true) {
                        continue;
                    }
                    int num = digits[i] + 10 * digits[j] + 100 * digits[k];
                    if (num < 100 || nums.count(num)) {
                        continue;
                    }
                    ans.push_back(num);
                    nums.insert(num);
                }
                visited[j] = false;
            }
            visited[i] = false;
        }
        
        sort(ans.begin(), ans.end());
        return ans;

    }
};

/* Official Solution 1 */
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> nums;   // 目标偶数集合
        int n = digits.size();
        // 遍历三个数位的下标
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                for (int k = 0; k < n; ++k){
                    // 判断是否满足目标偶数的条件
                    if (i == j || j == k || i == k){
                        continue;
                    }
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    if (num >= 100 && num % 2 == 0){
                        nums.insert(num);
                    }
                }
            }
        }
        // 转化为升序排序的数组
        vector<int> res;
        for (const int num: nums){
            res.push_back(num);
        }
        sort(res.begin(), res.end());
        return res;
    }
};

/* Official Solution 2 */
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;   // 目标偶数数组
        unordered_map<int, int> freq;   // 整数数组中各数字的出现次数
        for (const int digit: digits){
            ++freq[digit];
        }
       // 枚举所有三位偶数，维护整数中各数位的出现次数并比较判断是否为目标偶数
        for (int i = 100; i < 1000; i += 2){
            unordered_map<int, int> freq1;
            int tmp = i;
            while (tmp){
                ++freq1[tmp%10];
                tmp /= 10;
            }
            if (all_of(freq1.begin(), freq1.end(), [&](const auto& x){
                    return freq[x.first] >= freq1[x.first]; 
                })){
                res.push_back(i);
            }
        }
        return res;
    }
};
