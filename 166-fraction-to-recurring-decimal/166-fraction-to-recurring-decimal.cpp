class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator == 0) return "";
        if(numerator == 0) return "0"; 
        
        long num = abs(numerator);
        long den = abs(denominator);
        unordered_map<long, int > ap;
        string s = "";
        
        s += string((numerator < 0) ^ (denominator < 0), '-'); 
        
        s+=to_string(num/den);
        
        num%=den;
        if(!num)
            return s;
        
        s +='.';
        
        
        long rem = num%den;
        while(rem)
        {
            ap[rem]= s.size();        
            rem *= 10;
            s += to_string(rem/den);
            rem %= den;
            if(ap.find(rem)!=ap.end()) {
                s.insert(ap[rem], "(");
                s+=')';
                break;
            }
        }
        
        
        return s;
        
        
        
        
    }
};