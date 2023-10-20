class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        long long maxd = max(length, max(width, height)), vol = 1L * length * width * height;
        bool isBulky = maxd >= 10000 || vol >= 1000000000, isHeavy = mass >= 100;
        if (isBulky && isHeavy) {
             return "Both";
        } else if (isBulky) {
            return "Bulky";
        } else if (isHeavy) {
            return "Heavy";
        } else {
            return "Neither";
        }
    }
};



class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool isBulky = false;
        bool isHeavy = false;
        const int maxDimension = 1e4;
        const long maxMult = 1e9;
        const int maxHeavy = 1e2;

        if (length >= maxDimension || width >= maxDimension || height >= maxDimension) {
            isBulky = true;
        }
        
        if (mass >= maxHeavy) {
            isHeavy = true;
        }
        
        if (isBulky == false) {
            long long mulVal = length * width;
            mulVal *= height;
            isBulky = mulVal < maxMult ? false : true;
        }
        
        if (isBulky && isHeavy) {
            return "Both";
        }
        
        if (isBulky) {
            return "Bulky";
        }
        
        if (isHeavy) {
            return "Heavy";
        }
        return "Neither";
    }
};