class Solution {
public:
    string longestPalindrome(string s) {
       string res;
        for(int left =0;left < s.size();left++) {
            for(int right = s.size() - left;res.size() < right;right--) {
                int l = left; 
                int r = left + right - 1;
                while(l <= r && s.at(l) == s.at(r)) { 
                    l++;
                    r--; 
                }
                if (l >= r) { 
                    res = s.substr(left, right); 
                } 
            }
        }
        
        return res;
        
    }
};