class Solution {
public:
    bool winnerOfGame(string colors) {
        int freq[2] = {0, 0};
        char cur = 'C';
        int cnt = 0;
        for (char c : colors) {
            if (c != cur) {
                cur = c;
                cnt = 1;
            } else if (++cnt >= 3) {
                ++freq[cur - 'A'];
            }
        }            
        return freq[0] > freq[1];
    }
};
