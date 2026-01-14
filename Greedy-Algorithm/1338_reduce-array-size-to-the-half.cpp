class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num: arr) {
            ++freq[num];
        }
        vector<int> occ;
        for (auto& [k, v]: freq) {
            occ.push_back(v);
        }
        sort(occ.begin(), occ.end(), greater<int>());
        int cnt = 0, ans = 0;
        for (int c: occ) {
            cnt += c;
            ans += 1;
            if (cnt * 2 >= arr.size()) {
                break;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> digitCnt;
        int nums = arr.size();
        
        for (int val : arr) {
            ++digitCnt[val];
        }
        
        vector<int> numsFreq(digitCnt.size(), 0);
        int i = 0;
        for (auto [_, cnt] : digitCnt) {
            numsFreq[i++] = cnt;
        }
        
        sort(numsFreq.begin(), numsFreq.end(), greater<int>());
        int cnt = 0;
        int setSize = 0;
        
        i = 0;
        while (cnt < nums / 2) {
            cnt += numsFreq[i++];
        }
        
        return i;
    }
};





class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> digitCnt;
        int nums = arr.size();
        
        for (int val : arr) {
            ++digitCnt[val];
        }
        
        priority_queue<int> pq;
        
        for (auto [_, cnt] : digitCnt) {
            pq.push(cnt);
        }
        
        int cnt = 0;
        int setSize = 0;
        
        while (cnt < nums / 2) {
            cnt += pq.top();
            pq.pop();
            ++setSize;
        }
        
        return setSize;
    }
};