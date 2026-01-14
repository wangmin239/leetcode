class Solution {
public:
    int calculate(string s) {
		int sum = 0;
		stack<int> dataSt;
		stack<char> opSt;
		int len = s.length();
		
		for (int i = 0; i < len; ) {
			if (s[i] == ' '){
				i++;
			} else if (s[i] == '+' || s[i] == '-'||
			         s[i] == '*' || s[i] == '/') {
				opSt.push(s[i]);
				i++;
			} else {
				int val = 0;
				while (i < len && isdigit(s[i])){
					val = val * 10 + (s[i] - '0');
					i++;
				}
				if (!opSt.empty()) {
					if (opSt.top() =='*') {
						val *= dataSt.top();
						dataSt.pop();
						opSt.pop();
					} else if(opSt.top() == '/') {
						val = dataSt.top() / val;
						dataSt.pop();
						opSt.pop();
					}
				}
				dataSt.push(val);
			}
		}
		/* calculating the addition and subtraction */
		stack<int> revDataSt;
		stack<char> revOpSt;
		while (!opSt.empty()) {
			revOpSt.push(opSt.top());
			opSt.pop();
			revDataSt.push(dataSt.top());
			dataSt.pop();
		}
		if (!dataSt.empty()){
			sum = dataSt.top();
			dataSt.pop();
		}
		while (!revOpSt.empty()) {
			char op = revOpSt.top();
			revOpSt.pop();
			int val = revDataSt.top();
			revDataSt.pop();
			if (op == '+') {
				sum += val;
			} else {
				sum -= val;
			}	
		}
		return sum;
    }
};



class Solution {
public:
    int calculate(string s) {
		int sum = 0;
		stack<int> dataSt;
		stack<char> opSt;
		int len = s.length();
		
		/* initlizating the stack for calculating */
		dataSt.push(sum);
		opSt.push('+');
		
		for (int i = 0; i < len; ) {
			if (s[i] == ' '){
				i++;
			} else if (s[i] == '+' || s[i] == '-') {		
				int val = dataSt.top();
				char op = opSt.top();
				if (op == '+') {
					sum += val;
				} else {
					sum -= val;
				}
				dataSt.pop();
				dataSt.push(sum);
				opSt.pop();
				opSt.push(s[i]);
                i++;
			} else if (s[i] == '*' || s[i] == '/') {
				opSt.push(s[i]);
                i++;
			}	
			else {
				int val = 0;
				while (i < len && isdigit(s[i])){
					val = val * 10 + (s[i] - '0');
					i++;
				}
				if (!opSt.empty()) {
					if (opSt.top() =='*') {
						val *= dataSt.top();
						dataSt.pop();
						opSt.pop();
					} else if(opSt.top() == '/') {
						val = dataSt.top() / val;
						dataSt.pop();
						opSt.pop();
					}
				}
				dataSt.push(val);
			}
		}
		/* calculating the addition and subtraction */
		if (!dataSt.empty()) {
			if (opSt.top() == '+') {
				sum += dataSt.top();
			} else {
				sum -= dataSt.top();
			}
		}
		return sum;
    }
};

class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) {
                switch (preSign) {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                }
                preSign = s[i];
                num = 0;
            }
        }
        return accumulate(stk.begin(), stk.end(), 0);
    }
};
