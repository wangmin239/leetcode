/* Original Solution, Time out */
class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        pArr = arr;
    }
    
    int query(int left, int right, int value) {
        int freq = 0;
        
        for (int i = left; i <= right; i++) {
            if (value == pArr[i]) {
                freq++;
            }
        }
        return freq;
    }

private:
    vector<int> pArr;
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
 
 

/* Official Solution */
class RangeFreqQuery {
private: 
    // 数值为键，出现下标数组为值的哈希表
    unordered_map<int, vector<int>> occurence;
    
public:
    RangeFreqQuery(vector<int>& arr) {
        // 顺序遍历数组初始化哈希表
        int n = arr.size();
        for (int i = 0; i < n; ++i){
            occurence[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        // 查找对应的出现下标数组，不存在则为空
        const vector<int>& pos = occurence[value];
        // 两次二分查找计算子数组内出现次数
        auto l = lower_bound(pos.begin(), pos.end(), left);
        auto r = upper_bound(pos.begin(), pos.end(), right);
        return r - l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
 
