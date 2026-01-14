class Solution {
public:
    int maxNumberOfBalloons(string text) {
        const int NUM = 26;
        int arr[NUM] = {0};
        
        for (char ch : text) {
            arr[ch - 'a']++;
        }
        
        int num = INT_MAX;
        char target[] = {'a', 'b', 'n'};
        for (char ch : target) {
            num = min(num, arr[ch - 'a']);
        }
        
        char doubleCh[] = {'l', 'o' };
        for (char ch : doubleCh) {
            num = min(num, arr[ch - 'a'] / 2);
        }
        
        return num;
    }
};




class Solution {
public:
    int maxNumberOfBalloons(string text) {
        const int NUM = 26;
        int arr[NUM] = {0};
        
        for (char ch : text) {
            arr[ch - 'a']++;
        }
        
        int num = INT_MAX;
        for (char ch : string("abn")) {
            num = min(num, arr[ch - 'a']);
        }
        
        for (char ch : string("lo")) {
            num = min(num, arr[ch - 'a'] / 2);
        }
        
        return num;
    }
};



class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> cnt(5);
        for (auto & ch : text) {
            if (ch == 'b') {
                cnt[0]++;
            } else if (ch == 'a') {
                cnt[1]++;
            } else if (ch == 'l') {
                cnt[2]++;
            } else if (ch == 'o') {
                cnt[3]++;
            } else if (ch == 'n') {
                cnt[4]++;
            }
        }
        cnt[2] /= 2;
        cnt[3] /= 2;
        return *min_element(cnt.begin(), cnt.end());
    }
};
