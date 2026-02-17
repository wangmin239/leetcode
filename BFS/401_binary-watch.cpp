/* Original Solution 1 */
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
      if (turnedOn > 8) {
        return {};
      }
      int hours[] = {1, 2, 4, 8};
      int minutes[] = {1, 2, 4, 8, 16, 32};
      vector<string> ans;
      unordered_set<int> value;

      auto dfs = [&](int hour, int minute, int turnedOn, auto&& self) {
          if (turnedOn < 0 || hour > 11 || minute > 59) {
              return;
          }

          if (turnedOn == 0) {
              if (value.count(hour * 60 + minute)) {
                  return;
              }
              value.insert(hour * 60 + minute);
              string time(to_string(hour));

              if (minute < 10) {
                  ans.push_back(time + ":0" + to_string(minute));
              } else {
                  ans.push_back(time + ":" + to_string(minute));
              }
          }



          for (int i = 0; i < 6; i++) {
              if (minute & minutes[i]) {
                  continue;
              }
              self(hour, minute + minutes[i], turnedOn - 1, self);
          }

          for (int i = 0; i < 4; i++) {
              if (hour & hours[i]) {
                  continue;
              }
              self(hour + hours[i], minute, turnedOn - 1, self);
          }
      };

      dfs(0, 0, turnedOn, dfs);
      return ans;
    }
};



/* Original Solution 2 */
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
      if (turnedOn > 8) {
        return {};
      }

      vector<string> ans;
      unsigned int limit = 0x400;
      const int decimal = 10;
      int maxHour = 12;
      int maxMinute = 60;

      auto timeStr = [decimal](int hour, int minute) {
          string time;

          if (hour >= decimal) {
              time.push_back('1');
          }

          time.push_back('0' + hour % decimal);
          time.push_back(':');

          if (minute < decimal) {
              time.push_back('0');
          }

          time.append(to_string(minute));
          return time;
      };

      for (unsigned int i = 0; i < limit; i++) {
          if (popcount(i) != turnedOn) {
              continue;
          }

          int minute = 0;
          int shift;
          for (shift = 0; shift < 6; shift++) {
              int mask = 1 << shift;
              if (i & mask) {
                  minute += mask;
              }
          }

          if (minute >= maxMinute) {
              continue;
          }
          int hour = 0;
          while (shift < decimal) {
              int mask = 1 << shift;
              if (i & mask) {
                  hour += 1 << (shift - 6);
              }
              ++shift;
          }

          if (hour >= maxHour) {
              continue;
          }

          ans.push_back(timeStr(hour, minute));
      }

      return ans;
    }
};


/* Official Solution 1 */
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


/* Official Solution 2 */
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
