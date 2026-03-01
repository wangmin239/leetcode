/* Original Solution 1 */
class Solution {
public:
    int minPartitions(string n) {
        int num = 0;

        for (char ch : n) {
            int digit = ch - '0';

            num = max(num, digit);
        }

        return num;
    }
};