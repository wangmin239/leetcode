class Solution {
public:
    string solveEquation(string equation) {
        int leftX = 0;
        int leftVal = 0;
        int rightX = 0;
        int rightVal = 0;
        
        auto pos = equation.find('=', 0);
        auto leftStr = equation.substr(0, pos);
        auto rightStr = equation.substr(pos + 1);
        
        parseStr(leftStr, leftX, leftVal);
        parseStr(rightStr, rightX, rightVal);
        
        if (leftX == rightX && leftVal == rightVal) {
            return "Infinite solutions";
        }
        
        if (leftX == rightX && leftVal != rightVal) {
            return "No solution";
        }        
        
        leftX -= rightX;
        rightVal -= leftVal;
        
        int xValue = rightVal / leftX;
        
        if (leftX == 0 && rightVal == 0) {
            return "Infinite solutions";
        }
        
        return "x=" + to_string(xValue);
    }
    
    void parseStr(string str, int& numX, int& value) {
       int len = str.length();

       for (int i = 0; i < len; i++) {
           int isPositive = 1;
           string digits;
           int num = 0;

           if (str[i] == '-') {
               isPositive = -1;
               i++;
           }
           
           if (str[i] == '+') {
               isPositive = 1;
               i++;
           } 
           
           while(i < len && isdigit(str[i])) {
              digits.push_back(str[i]);
              i++;
           }
           
           if (digits.empty() == false) {
                num = stoi(digits);
           }
           
           if (i < len && str[i] == 'x') {
               if (digits.empty()) {
                   numX += isPositive * 1;
               } else {
                    numX += isPositive * num;
               }
               continue;
           }
           --i;
           value += isPositive * num;
       }
    }
};




class Solution {
public:
    string solveEquation(string equation) {
        int factor = 0, val = 0;
        int index = 0, n = equation.size(), sign1 = 1; // 等式左边默认系数为正
        while (index < n) {
            if (equation[index] == '=') {
                sign1 = -1; // 等式右边默认系数为负
                index++;
                continue;
            }

            int sign2 = sign1, number = 0;
            bool valid = false; // 记录 number 是否有效
            if (equation[index] == '-' || equation[index] == '+') { // 去掉前面的符号
                sign2 = (equation[index] == '-') ? -sign1 : sign1;
                index++;
            }
            while (index < n && isdigit(equation[index])) {
                number = number * 10 + (equation[index] - '0');
                index++;
                valid = true;
            }

            if (index < n && equation[index] == 'x') { // 变量
                factor += valid ? sign2 * number : sign2;
                index++;
            } else { // 数值
                val += sign2 * number;
            }
        }

        if (factor == 0) {
            return val == 0 ? "Infinite solutions" : "No solution";
        }
        return string("x=") + to_string(-val / factor);
    }
};
