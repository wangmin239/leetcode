/* Original Soution 1 */
class Solution {
public:
    string digitSum(string s, int k) {
        int len = s.length();
        const int decimal = 10;


        while (len > k) {
            int sum = 0;
            int left = 0;
            int nextLen = 0;
            
            for (int i = 0; i < len; i++) {
                sum += s[i] - '0';

                if ((i + 1) % k == 0 || i == len - 1) {
                    if (sum == 0) {
                        s[left++] = '0';
                        ++nextLen;
                        continue;
                    }

                    int right = left;
                    while (sum) {
                        s[right++] = '0' + sum % decimal;
                        sum /= decimal;
                        ++nextLen;
                    }

                    while (left < --right) {
                        swap(s[left++], s[right]);
                    }

                    left = nextLen;
                }
            }
            
            len = nextLen;
            
        }
        
        return s.substr(0, len);
    }
};

/* Official Solution 1 */
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            int n = s.size();
            string t;
            for (int i = 0; i < n; i += k) { // k 个一组
                int sum = 0;
                for (int j = i; j < min(i + k, n); j++) {
                    sum += s[j] - '0'; // 计算数字和
                }
                t += to_string(sum);
            }
            s = move(t);
        }
        return s;
    }
};


/* Official Solution 2 */
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string tmp;   // 每次操作结束的字符串
            int n = s.size();
            for (int i = 0; i < n; i += k) {
                int val = 0;
                for (int j = i; j < min(i + k, n); ++j) {
                    val += s[j] - '0';
                }
                tmp.append(to_string(val));
            }
            s = tmp;
        }
        return s;
    }
};
