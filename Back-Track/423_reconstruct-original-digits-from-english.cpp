reconstruct-original-digits-from-english

class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> c;
        for (char ch: s) {
            ++c[ch];
        }

        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];

        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};

class Solution {
private:
    string ans;
public:
    string originalDigits(string s) {
        const int tableSize = 26;
        int charTable[tableSize] = {0};
        
        for (char ch : s) {
            charTable[ch - 'a']++;
        }
        
        string str;
        dfs(str, charTable, tableSize, 0);
        return ans;
        
    }
    
    void dfs(string& str, int table[], int len, int digit) {
        if (digit > 9) {
            return;
        }
        
        if (tableIsClear(table, len) == true) {
            this->ans = str;
            return;
        }
        
        for (int i = digit; i < 10; i++) {
            if (isMatch(i, table) != true) {
                continue;
            }
            operatorTable(i, table, false);
            str.push_back('0' + i);
            dfs(str, table, len, i);
            str.pop_back();
            operatorTable(i, table, true);            
        }
    }
    
    bool tableIsClear(int table[], int len) {
        for (int i = 0; i < len; i++) {
            if (table[i] != 0) {
                return false;
            }
        }
        return true;
    }
    
    bool isMatch(const int digit, int table[]) {
        /* check if is matched */
        string arr[] = {"zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};
        
        string digitStr = arr[digit];
        for (char ch : digitStr) {
            if (table[ch - 'a'] < 1) {
                return false;
            }
        }
        return true;
    }
    
    void operatorTable(int digit, int table[], bool increase) {
        string arr[] = {"zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"};
        
        string digitStr = arr[digit];
        
        if (increase == true) {
            for (char ch : digitStr) {
                table[ch - 'a']++;
            }
        }            
        else {
            for (char ch : digitStr) {
                table[ch - 'a']--;
            }
            
        }
    }
    
};