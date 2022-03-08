class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> answer(n, 0);
        int index = 0;
        
        for (const auto query : queries) {
            int begin = query.front();
            int end = query.back();
            bool leftFlag = false;
            
            while (begin != end) {
                    int left = begin;
                    for (int i = left; i <= end; i++) {
                        if (s[i] != '|') {
                            break;
                        }
                        left = i;
                        leftFlag = true;
                    }
                    
                    int right = left + 1;
                    bool rightFlag = false;
                    
                    for (int i = right; i <= end; i++) {
                        if (s[i] == '|') {
                            right = i;
                            rightFlag = true;
                            break;
                        }
                    }
                    
                    int num = 0;
                    if (rightFlag && leftFlag) {
                        num = right - left - 1;
                    }
                    
                    begin = right;
                    leftFlag = rightFlag;
                    answer[index] += num;
            }
            index++;
        }
                    
        return answer;

    }
};

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> preSum(n);
        for (int i = 0, sum = 0; i < n; i++) {
            if (s[i] == '*') {
                sum++;
            }
            preSum[i] = sum;
        }
        vector<int> left(n);
        for (int i = 0, l = -1; i < n; i++) {
            if (s[i] == '|') {
                l = i;
            }
            left[i] = l;
        }
        vector<int> right(n);
        for (int i = n - 1, r = -1; i >= 0; i--) {
            if (s[i] == '|') {
                r = i;
            }
            right[i] = r;
        }
        vector<int> ans;
        for (auto& query : queries) {
            int x = right[query[0]], y = left[query[1]];
            ans.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x]);
        }
        return ans;
    }
};




class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> answer(n, 0);
        function<int(const string&, bool, int, int)> dfs = [&] (const string& s, bool flag, int left, int right) {
            int begin = left;
            bool leftFlag = flag;
            for (int i = begin; i <= right; i++) {
                if (s[i] != '|') {
                    break;
                }
                begin = i;
                leftFlag = true;
            }
            
            int end = begin + 1;
            bool rightFlag = false;
            for (int i = end; i <= right; i++) {
                if (s[i] == '|') {
                    end = i;
                    rightFlag = true;
                    break;
                }
            }
            
            int num = 0;
            if (rightFlag && leftFlag) {
                num = end - begin - 1;
            }
            
            return  right < end ? num : num + dfs(s, rightFlag, end, right);
        };
        
        int i = 0;
        for (const auto& query : queries) {
            int left = query.front();
            int right = query.back();
            answer[i++] = dfs(s, false, left, right);
        }
        
        return answer;

    }
};