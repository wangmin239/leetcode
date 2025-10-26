/* Original Solution 1 */
class Bank {
public:
    shared_ptr<long long []> users;
    int n;
    Bank(vector<long long>& balance) {
        n = balance.size() + 1;
        
        users = make_shared<long long []>(n);
        
        for (int i = 0; i < n - 1; i++) {
            users[i + 1] = balance[i];
        }
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 > n) {
            return false;
        }
        
        if (users[account1] < money) {
            return false;
        }
        
        users[account1] -= money;
        users[account2] += money;
        
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > n) {
            return false;
        }
        
        users[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > n) {
            return false;
        }
        
        if (users[account] < money) {
            return false;
        }
        
        users[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
 
 
 
 
 /* Original Solution 1 */
class Bank {
public:
    long long *users;
    int n;
    Bank(vector<long long>& balance) {
        n = balance.size() + 1;
        
        users = new long long [n];
        
        for (int i = 0; i < n - 1; i++) {
            users[i + 1] = balance[i];
        }
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 > n) {
            return false;
        }
        
        if (users[account1] < money) {
            return false;
        }
        
        users[account1] -= money;
        users[account2] += money;
        
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > n) {
            return false;
        }
        
        users[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > n) {
            return false;
        }
        
        if (users[account] < money) {
            return false;
        }
        
        users[account] -= money;
        return true;
    }
    virtual ~Bank() {
        delete [] users;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
 
 
 /* Official Solution 1 */
 class Bank {
    vector<long long> b;

public:
    Bank(vector<long long>& balance) : b(balance) {}

    bool transfer(int account1, int account2, long long money) {
        if (account1 > b.size() || account2 > b.size() || b[account1 - 1] < money) {
            return false;
        }
        b[account1 - 1] -= money;
        b[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (account > b.size()) {
            return false;
        }
        b[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (account > b.size() || b[account - 1] < money) {
            return false;
        }
        b[account - 1] -= money;
        return true;
    }
};
