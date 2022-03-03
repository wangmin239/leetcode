class Solution {
public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        }
        
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        
        return addDigits(sum);
    }
};




class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        
        while (num > 9) {
            sum = 0;
            while (num != 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return sum;
    }
};


class Solution {
public:
    int addDigits(int num)
    {
         if (num == 0){
            return 0;
        }
        int s = num % 9;
        if(s == 0){
            return 9;
        }else return s;
    }
        
    
};



class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};
