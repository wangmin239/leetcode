class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int num1Real;
        int num1Virt;
        int num2Real;
        int num2Virt;
        
        auto pos1 = getReal(num1, num1Real);
        num1Virt = getVirt(num1, pos1);
        
        auto pos2 = getReal(num2, num2Real);
        num2Virt = getVirt(num2, pos2);
       
       int realVal = num1Real * num2Real - num1Virt * num2Virt;
       int virtVal = num1Real * num2Virt + num2Real * num1Virt;
       
       return to_string(realVal) + "+" + to_string(virtVal) + "i";
    }
    
    inline int getReal(const string& num, int& realVal) {    
        auto pos = num.find('+');
        realVal = stoi(num.substr(0, pos));
        return  pos;
    }
    
    inline int getVirt(const string& num, int pos) {
        auto end = num.find('i', pos);
        int virtVal = stoi(num.substr(pos + 1, end - pos -1));
        return virtVal;
    }
    

};


class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        regex re("\\+|i"); 
        vector<string> complex1(sregex_token_iterator(num1.begin(), num1.end(), re, -1), std::sregex_token_iterator());
        vector<string> complex2(sregex_token_iterator(num2.begin(), num2.end(), re, -1), std::sregex_token_iterator());
        int real1 = stoi(complex1[0]);
        int imag1 = stoi(complex1[1]);
        int real2 = stoi(complex2[0]);
        int imag2 = stoi(complex2[1]);
        return to_string(real1 * real2 - imag1 * imag2) + "+" + to_string(real1 * imag2 + imag1 * real2) + "i";
    }
};


class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        auto get = [](string& s){
            complex<int> x;
            stringstream ss(s);
            int i, r; char c;
            ss >> r >> c >> i;
            return complex<int>(r, i);
        };
        auto a = get(num1) * get(num2);
        return to_string(a.real()) + '+' + to_string(a.imag()) + 'i';
    }
};