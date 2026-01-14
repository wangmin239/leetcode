class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        const int size = 26;
        int lowCh[size] = {0};
        int uppCh[size] = {0};
        
        /* find out that which character represents an jewel */
        for (char ch : jewels) {
            if (islower(ch)) {
                lowCh[ch - 'a'] = 1;
            } else {
                uppCh[ch - 'A'] = 1;
            }
        }
        /* calculating the number of jewel in one given string */
        int num = 0;
        for (char ch : stones) {
            if (islower(ch)) {
                if (lowCh[ch - 'a'] == 1) {
                    ++num;
                }
            } else {
                if (uppCh[ch - 'A'] == 1) {
                    ++num;
                }
            }
        }
        return num;
    }
};


class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewelsCount = 0;
        int jewelsLength = jewels.length(), stonesLength = stones.length();
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            for (int j = 0; j < jewelsLength; j++) {
                char jewel = jewels[j];
                if (stone == jewel) {
                    jewelsCount++;
                    break;
                }
            }
        }
        return jewelsCount;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewelsCount = 0;
        unordered_set<char> jewelsSet;
        int jewelsLength = jewels.length(), stonesLength = stones.length();
        for (int i = 0; i < jewelsLength; i++) {
            char jewel = jewels[i];
            jewelsSet.insert(jewel);
        }
        for (int i = 0; i < stonesLength; i++) {
            char stone = stones[i];
            if (jewelsSet.count(stone)) {
                jewelsCount++;
            }
        }
        return jewelsCount;
    }
};

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        long long mask = 0;
        for (char c: jewels)
            mask |= 1LL << (c & 63);
        int ans = 0;
        for (char c: stones)
            ans += mask >> (c & 63) & 1;
        return ans;
    }
};