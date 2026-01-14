class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> count;
        for (auto x : nums) {
            if (x % 2 == 0) {
                count[x]++;
            }
        }
        int res = -1, ct = 0;
        for (auto &p : count) {
            if (res == -1 || p.second > ct || p.second == ct && res > p.first) {
                res = p.first;
                ct = p.second;
            }
        }
        return res;
    }
};


class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> digitMap;
        
        for (vector<int>::size_type i = 0; i < nums.size(); i++) {
            if ((nums[i] & 0x1) == 0x1) {
                continue;
            }
            ++digitMap[nums[i]];
        }
        pair<int, int> cur(-1, 0);
        for (auto& [num, cnt] : digitMap) {
            if (cnt > cur.second) {
                cur.first = num;
                cur.second = cnt;
                continue;
            }
            
            if (cnt == cur.second) {
                if (num < cur.first) {
                    cur.first = num;
                }
            }
        }
        return cur.first;
    }
};

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int len = nums.size();
      pair<int, int> cur(-1, 0);
      
      for (int i = 0; i < len; i++) {
          if ((nums[i] & 0x1) == 0x1) {
              continue;
          }
          int cnt = 1;
          while (i < len - 1) {
              if (nums[i] != nums[i + 1]) {
                  break;
              }
              ++cnt;
              ++i;
          }
          if (cnt > cur.second) {
              cur.first = nums[i];
              cur.second = cnt;
          } 
      }
      return cur.first;
    }
};

