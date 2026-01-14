class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        unordered_map<int, int> count;
        for (int a : changed) {
            count[a]++;
        }
        vector<int> res;
        for (int a : changed) {
            if (count[a] == 0) {
                continue;
            }
            count[a]--;
            if (count[a * 2] == 0) {
                return {};
            }
            count[a * 2]--;
            res.push_back(a);
        }
        return res;
    }
};



class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int num = changed.size();
        
        if (num & 0x1) {
            return {};
        }
        
        unordered_map<int, int> freq;
        int n = num / 2;
        vector<int> origin(n);
        
        sort(changed.begin(), changed.end());
        for (int val : changed) {
            ++freq[val];
        }
        
        if (freq.count(0) && (freq[0] & 0x1)) {
            return {};
        }
        
        int index = 0;
        for (const int val : changed) {
            if (freq[val] == 0) {
                continue;
            }
            
            int doubleVal = val << 1;
            if (freq.count(doubleVal) == 0 || freq[doubleVal] < freq[val]) {
                return {};
            }
            
            --freq[doubleVal];
            --freq[val];
            origin[index++] = val;
            
            if (index == n) {
                break;
            }
        }
        
        return origin;
    }
};