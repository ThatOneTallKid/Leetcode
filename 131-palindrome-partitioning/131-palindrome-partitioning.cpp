class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        
        dfs(res, path, 0, s);
        return res;
    }
    
    
    void dfs(vector<vector<string>> &res, vector<string> &path, int idx, string s) {
        if(idx == s.size()) {
            res.push_back(path);
            return;
        }
        
        for(int i = idx;i < s.size();i++) {
            if(ispal(s, idx, i)) {
                path.push_back(s.substr(idx, i - idx+1));
                dfs(res, path, i+1, s);
                path.pop_back();
            }
        }
    }
    
    bool ispal(string s, int i, int j) {
        while(i <= j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        
        return true;
    }
};