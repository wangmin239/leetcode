class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int m = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            m = max(m, arr[i]);
            if (m == i) {
                res++;
            }
        }
        return res;
    }
};



class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int len = arr.size();
        int val;
        int pos, prePos;
        int banks = 0;

        for (val = pos = prePos = 0; pos < len; ) {
            pos = getIndex(val, arr, prePos);
            if (pos == -1) {
                return 1;
            }
            int maxVal = *max_element(arr.begin() + prePos, arr.begin() + pos);
            if (pos < maxVal) {
                pos = maxVal;
            }
            ++banks;
            ++pos;
            val = pos;
            prePos = pos;
        }
        return banks;
    }
    
    int getIndex(int val, vector<int>& arr, int pos) {
        int len = arr.size();
        
        while (pos < len) {
            if (val == arr[pos]) {
                return pos;
            }
            ++pos;
        }
        return -1;
    }
};