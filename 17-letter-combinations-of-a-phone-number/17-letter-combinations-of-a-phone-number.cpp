class Solution {
public:
    vector<string> ans;
    void dfs(vector<string> &v, string temp, string digits, int i) {
        if(i == digits.size() ) {
            ans.push_back(temp);
            return;
        }
        int dig = digits[i]-'0';
        string x = v[dig];
        for( int j = 0;j < x.size();j++) {
            
            dfs(v,temp+x[j],digits,i+1 );
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return ans;
        }
        
        string temp;
        vector<string> v{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        dfs(v,temp,digits, 0);
        return ans;
    }
};