class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // 若 k 能被 2 或 5 整除，则无解，返回 -1
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        // 初始化余数为 1，表示一个数的最低位是 1
        int resid = 1 % k, len = 1;
        // 若余数不为 0，继续迭代
        while (resid != 0) {
            // 计算下一个数的余数，下一个数在当前余数后加一个 1
            resid = (resid * 10 + 1) % k;
            len++;
        }
        // 返回数字 1 的最小重复次数
        return len;
    }
};


class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int resid = 1 % k, len = 1; // resid为余数，len为数字长度，初始值为1
        unordered_set<int> st; // 创建一个无序集合，用于存储余数
        st.insert(resid); // 插入余数1
        while (resid != 0) { // 当余数为0时退出循环
            resid = (resid * 10 + 1) % k; // 计算下一个余数
            len++; // 数字长度+1
            if (st.find(resid) != st.end()) { // 如果余数重复出现，则无解
                return -1;
            }
            st.insert(resid); // 将余数插入集合
        }
        return len; // 返回数字长度
    }
};
