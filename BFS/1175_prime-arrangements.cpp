class Solution {
public:
    int numPrimeArrangements(int n) {
        const int mode = 1e9 + 7;
        auto isPrime = [](const int num) {
            if ( num == 1) {
                return false;
            }
            
            for (int i = 2; i * i <= num; i++) {
                if (num % i == 0) {
                    return false;
                }
            }
            return true;
        };
        
        function<long(int)> factory = [&](int num) {
            if (num < 1) {
                return static_cast<long>(1);
            }
            
            return static_cast<long>(num * factory(num - 1)) % mode;
        };
        
        int primeNum = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) {
                primeNum++;
            }
        }
        
        return  factory(primeNum) * factory(n - primeNum) % mode;
    }
    
    
};