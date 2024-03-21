class FrequencyTracker {
public:
    unordered_map<int, int> digits;
    unordered_map<int, int> freq;
    FrequencyTracker() {

    }
    
    void add(int number) {
        int curFreq = ++digits[number];
        
        ++freq[curFreq];
        if (curFreq == 1) {
            return ;
        } 

        if (--freq[curFreq - 1] == 0) {
            freq.erase(curFreq - 1);
        }
    }
    
    void deleteOne(int number) {
        if (digits.count(number) != 0) {
            int curFreq = digits[number];
            
            if (--digits[number] == 0) {
                digits.erase(number);
            } else {
                ++freq[digits[number]];
            }
            
            if (--freq[curFreq] == 0) {
                freq.erase(curFreq);
            }

        }
        
        
    }
    
    bool hasFrequency(int frequency) {
        
        return freq.count(frequency) ? true : false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */