/* Original Solution 1 */
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        constexpr int maxNum = 128;
        shared_ptr<int[]> sPtr(new int[maxNum] {0});
        

        for (int num : nums) {
            ++sPtr[num];
        }
        
        sort(sPtr.get(), sPtr.get() + maxNum, greater<int>());
        
        int maxFreq = sPtr[0];
        int sum = 0;
        
        for (int i = 0; i < maxNum; i++) {
            if (sPtr[i] == maxFreq) {
                sum += maxFreq;
                continue;
            }
            break;
        }
        
        return sum;
    }
};

/* Original Solution 2 */
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        constexpr int maxNum = 128;
        shared_ptr<int[]> sPtr(new int[maxNum]);
        int* ptr = sPtr.get();
        
        fill_n(ptr, maxNum, 0);
        for (int num : nums) {
            ++ptr[num];
        }
        
        sort(ptr, ptr + maxNum, greater<int>());
        
        int maxFreq = ptr[0];
        int sum = 0;
        
        for (int i = 0; i < maxNum; i++) {
            if (ptr[i] == maxFreq) {
                sum += maxFreq;
                continue;
            }
            break;
        }
        
        return sum;
    }
};