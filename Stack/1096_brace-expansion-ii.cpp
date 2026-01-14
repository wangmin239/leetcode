class Solution {
    string expression;
    int idx;

    // item -> letter | { expr }
    set<string> item() {
        set<string> ret;
        if (expression[idx] == '{') {
            idx++;
            ret = expr();
        } else {
            ret = {string(1, expression[idx])};
        }
        idx++;
        return move(ret);
    }

    // term -> item | item term
    set<string> term() {
        // 初始化空集合，与之后的求解结果求笛卡尔积
        set<string> ret = {""};
        // item 的开头是 { 或小写字母，只有符合时才继续匹配
        while (idx < expression.size() && (expression[idx] == '{' || isalpha(expression[idx]))) {
            auto sub = item();
            set<string> tmp;
            for (auto &left : ret) {
                for (auto &right : sub) {
                    tmp.insert(left + right);
                }
            }
            ret = move(tmp);
        }
        return move(ret);
    }

    // expr -> term | term, expr
    set<string> expr() {
        set<string> ret;
        while (true) {
            // 与 term() 求解结果求并集
            ret.merge(term());
            // 如果匹配到逗号则继续，否则结束匹配
            if (idx < expression.size() && expression[idx] == ',') {
                idx++;
                continue;
            } else {
                break;
            }
        }
        return move(ret);
    }

public:
    vector<string> braceExpansionII(string expression) {
        this->expression = expression;
        this->idx = 0;
        auto ret = expr();
        return {ret.begin(), ret.end()};
    }
};

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<char> op;
        vector<set<string>> stk;

        // 弹出栈顶运算符，并进行计算
        auto ope = [&]() {
            int l = stk.size() - 2, r = stk.size() - 1;
            if (op.back() == '+') {
                stk[l].merge(stk[r]);
            } else {
                set<string> tmp;
                for (auto &left : stk[l]) {
                    for (auto &right : stk[r]) {
                        tmp.insert(left + right);
                    }
                }
                stk[l] = move(tmp);
            }
            op.pop_back();
            stk.pop_back();
        };

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == ',') {
                // 不断地弹出栈顶运算符，直到栈为空或者栈顶不为乘号
                while (op.size() && op.back() == '*') {
                    ope();
                }
                op.push_back('+');
            } else if (expression[i] == '{') {
                // 首先判断是否需要添加乘号，再将 { 添加到运算符栈中
                if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
                    op.push_back('*');
                }
                op.push_back('{');
            } else if (expression[i] == '}') {
                // 不断地弹出栈顶运算符，直到栈顶为 {
                while (op.size() && op.back() != '{') {
                    ope();
                }
                op.pop_back();
            } else {
                // 首先判断是否需要添加乘号，再将新构造的集合添加到集合栈中
                if (i > 0 && (expression[i - 1] == '}' || isalpha(expression[i - 1]))) {
                    op.push_back('*');
                }
                stk.push_back({string(1, expression[i])});
            }
        }
        
        while (op.size()) {
            ope();
        }
        return {stk.back().begin(), stk.back().end()};
    }
};
