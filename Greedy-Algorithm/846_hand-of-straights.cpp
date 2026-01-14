class Solution {
public:
   bool isNStraightHand(vector<int>& hand, int groupSize) {
       int len = hand.size();
       if (0 != (len % groupSize)) {
           return false;
       }
       
       int groupNum = len / groupSize;
       map<int, int>   count;
       for (auto val : hand) {
           count[val]++;
       }

       
       for (pair<int, int> pair : count) {
           int val = pair.first;
           int cnt = pair.second;
           if (cnt > groupNum) {
               return false;
           }
           
           if (cnt > 0) {
               int prevCnt = cnt;
               for (int i = 1; i < groupSize; ++i) {
                   int curVal = val + i;
                   if (count[curVal] < prevCnt) {
                       return false;
                   }
                   prevCnt = count[curVal];
                   count[curVal] -= cnt;
               }
           }
       }

       return true;
   }
};


class Solution {
public:
   bool isNStraightHand(vector<int>& hand, int groupSize) {
       int len = hand.size();
       if (0 != (len % groupSize)) {
           return false;
       }
       
       int groupNum = len / groupSize;
       map<int, int>   count;
       for (auto val : hand) {
           count[val]++;
       }

       
       for (auto [val, cnt] : count) {
           if (cnt > groupNum) {
               return false;
           }
           
           if (cnt > 0) {
               int prevCnt = cnt;
               for (int i = 1; i < groupSize; ++i) {
                   int curVal = val + i;
                   if (count[curVal] < prevCnt) {
                       return false;
                   }
                   prevCnt = count[curVal];
                   count[curVal] -= cnt;
               }
           }
       }

       return true;
   }
};

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        sort(hand.begin(), hand.end());
        unordered_map<int, int> cnt;
        for (auto & num : hand) {
            cnt[num]++;
        }
        for (auto & x : hand) {
            if (!cnt.count(x)) {
                continue;
            }
            for (int j = 0; j < groupSize; j++) {
                int num = x + j;
                if (!cnt.count(num)) {
                    return false;
                }
                cnt[num]--;
                if (cnt[num] == 0) {
                    cnt.erase(num);
                }
            }
        }
        return true;
    }
};


class Solution {
public:
   bool isNStraightHand(vector<int>& hand, int groupSize) {
       int len = hand.size();
       if (0 != (len % groupSize)) {
           return false;
       }
       
       map<int, int>   count;
       for (auto i : hand) {
           count[i]++;
       }

       for (auto &it : count) {
           if (it.second > 0) {
               for (int i = 1; i < groupSize; ++i) {
                   int handA = it.first + i;
                   count[handA] -= it.second;
                   if (count[handA] < 0) {
                       return false;
                   }
               }
           }
       }

       return true;
   }
};