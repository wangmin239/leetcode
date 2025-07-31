/* Original Solution 1 */
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        const int init = 1;
        int next = init;
        
        /* Calculate the each element of the orignal array */
        for (int i = 0; i < n - 1; i++) {
            next ^= derived[i];
        }
        
        return derived.back() == (next ^ init);
    }
};


/* Official Solution 1 */
class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return reduce(derived.begin(), derived.end(), 0, bit_xor()) == 0;
    }
};
