class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        money -= children;
        int cnt = min(money / 7, children);
        money -= cnt * 7;
        children -= cnt;
        if ((children == 0 && money > 0) || (children == 1 && money == 3)) {
            cnt--;
        }
        return cnt;
    }
};




class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        const int step = 7;
        money -= children
        int cnt = 0;
        int i;
        for (i = 0; i < children; i++) {
            money -= step;
            if (money < 0) {
                break;
            }
            ++cnt;
        }
        
        if (money > 0) {
            return cnt - 1;
        }

        if (money == 0) {
            return cnt;
        }
        
        if (i == children - 1 && money == -4) {
            return cnt - 1;
        }
        return cnt;
            
    }
};




class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children) {
            return -1;
        }
        const int div = 7;
        money -= children;
        int mul = money / div;
        int mod = money % div;
 
        
        if (mul >= children) {
            if (mul == children && mod == 0) {
                return mul;
            } else {
                return children - 1;
            }
        }
        
        if (mod == 3 && mul == children - 1) {
            mul -= 1;
        }
        return mul;
            
    }
};
