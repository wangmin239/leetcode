class Solution {
public:
    string printBin(double num) {
        int64_t m = *(int64_t*)&num;
        string s = bitset<64>(m).to_string();
        string ss(s.begin()+12, s.end());
        string ans = "0."s + string(1022-(m>>52), '0') + "1"s + ss;
        while (ans.back() == '0') {
            ans.pop_back();
        }
        return ans.size() <= 32 ? ans : "ERROR"s;
    }
};


class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        while (res.size() <= 32 && num != 0) {
            num *= 2;
            int digit = num;
            res.push_back(digit + '0');
            num -= digit;
        }
        return res.size() <= 32 ? res : "ERROR";
    }
};