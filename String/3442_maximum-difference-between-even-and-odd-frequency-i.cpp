/* Original Solution 1 */
class Solution {
public:
    int maxDifference(string s) {
       constexpr int limit = 26;
       int chArr[limit] = {{0}};
       
       for (char ch : s) {
           int index = static_cast<int>(ch - 'a');
           ++chArr[index];
       }
       
       int maxOdd = 1;
       int minEven = INT_MAX;
       
       for (int i = 0; i < limit; i++) {
           if (chArr[i] & 0x1) {
               maxOdd = max(chArr[i], maxOdd);
               continue;
           }
           if (chArr[i] > 0) {
               minEven = min(chArr[i], minEven);
           }
       }
       
       return maxOdd - minEven;
    }
};

/* Official Solution 1 */
class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> c;
        for (char ch: s) {
            ++c[ch];
        }
        int maxOdd = 1, minEven = s.size();
        for (const auto& [_, value]: c) {
            if (value % 2 == 1) {
                maxOdd = max(maxOdd, value);
            }
            else {
                minEven = min(minEven, value);
            }
        }
        return maxOdd - minEven;
    }
};
