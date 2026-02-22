/* Original Solution 1 */
class Solution {
public:
    int binaryGap(int n) {
        int distance = 0;
        bitset<32> binary(n);
        int left = 0, right;

        while (left < 32) {
            if (binary[left] == 1) {
                break;
            }
            ++left;
        }

        for (right = left; right < 32; right++) {
            if (binary[right] == 1) {
                distance = max(distance, right - left);
                left = right;
            }
        }

        return distance;
    }
};


/* Official Solution 1 */
class Solution {
public:
    int binaryGap(int n) {
        int last = -1, ans = 0;
        for (int i = 0; n; ++i) {
            if (n & 1) {
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
            n >>= 1;
        }
        return ans;
    }
};
