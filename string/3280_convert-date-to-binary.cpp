class Solution {
public:
    string convertDateToBinary(string date) {
        int year = stol(date.substr(0, 4));
        int month = stol(date.substr(5, 2));
        int day = stol(date.substr(8, 2));
        
        auto convert2Str = [](int num) {
            string str;
            
            while (num) {
                str.push_back('0' + num % 2);
                num /= 2;
            }
            
            reverse(str.begin(), str.end());
        };
        
        return convert2Str(year) + "-" + convert2Str(month) + "-" + convert2Str(day);
    }
};


class Solution {
public:
    string binary(int x) {
        string s;
        while (x) {
            s.push_back('0' + (x & 1));
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        return binary(year) + "-" + binary(month) + "-" + binary(day);
    }
};
