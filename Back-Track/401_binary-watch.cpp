class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 1024; ++i) {
            int h = i >> 6, m = i & 63; // 用位运算取出高 4 位和低 6 位
            if (h < 12 && m < 60 && __builtin_popcount(i) == turnedOn) {
                ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
            }
        }
        return ans;
    }
};



class Solution {
private:
    // 对应bit表示的对应时间的数字
    // 为什么保留这些额外的0是为了减少后续if判断
    int hours[10] = {1, 2, 4, 8, 0, 0, 0, 0, 0, 0};
    int minutes[10] = {0, 0, 0, 0, 1, 2, 4, 8, 16, 32};

    // res: 保存结果
    // turnedOn: 允许点亮的数量，会不断减少
    // index：当前遍历的起点
    // hour: 时
    // minute: 分
    void dfs(vector<string>& res, int turnedOn, int index, int hour, int minute)
    {
        if (hour > 11 || minute > 59)
        {
            return; 
        }
        else if (turnedOn == 0)
        {
            // 构建时间，这里要注意后面minute可能需要补零
            string curr = to_string(hour) + ":" + (minute < 10 ? "0"+to_string(minute) : to_string(minute));
            res.emplace_back(curr);
            return;
        }
        // 最多选择是10
        for (int i = index; i < 10; ++i)
        {
            // 这里无需判断，而是直接去数组里取，无效时候就是0
            dfs(res, turnedOn-1, i+1, hour + hours[i], minute + minutes[i]);
        }
    }

public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        dfs(res, turnedOn, 0, 0, 0);
        return res;
    }
};
