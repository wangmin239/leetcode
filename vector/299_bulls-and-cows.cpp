class Solution {
public:
    string getHint(string secret, string guess) {
        int cntA = 0;
        int cntB = 0;;
        int sDigits[10] = {0};
        int gDigits[10] = {0};
        int len = secret.length();
        
        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                cntA++;
                continue;
            }
            sDigits[secret[i] - '0']++;
            gDigits[guess[i] - '0']++;
        }
        
        for (int i = 0; i < sizeof(sDigits) / sizeof(sDigits[0]); i++) {
            cntB += min(sDigits[i], gDigits[i]);
        }
        
        return string(to_string(cntA) + "A" + to_string(cntB) + "B");

    }
};


class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        vector<int> cntS(10), cntG(10);
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                ++cntS[secret[i] - '0'];
                ++cntG[guess[i] - '0'];
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; ++i) {
            cows += min(cntS[i], cntG[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
