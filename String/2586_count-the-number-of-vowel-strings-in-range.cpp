class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        char arr[] = {'a', 'e', 'i', 'o', 'u'};
        int mask = 0;
        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
           mask |= 1 << (arr[i] - 'a');
        }
        
        auto check = [mask](const char ch) { 
          return (mask & (1 << (ch - 'a'))) != 0;
        };
        
        int cnt = 0;
        for (int i = left; i <= right; i++) {
            if (check(words[i].front()) && check(words[i].back())) {
                ++cnt;
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++) {
            string s = words[i];
            if (s.find_first_of("aeiou") == 0 && s.find_last_of("aeiou") == s.length() - 1) ans++;
        }
        return ans;
    }
};
