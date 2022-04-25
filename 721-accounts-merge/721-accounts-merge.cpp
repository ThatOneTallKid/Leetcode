class Solution {
public:
    string find(string s, map<string, string> &p) {
        return p[s] == s ? s : find(p[s], p);    
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& a) {
        map<string, string> owner;
        map<string, string> parent;
        map<string, set<string>> unions;
        
        for(int i =0;i<a.size();i++){
            for(int j =1;j<a[i].size();j++) {
                parent[a[i][j]] = a[i][j];
                owner[a[i][j]] = a[i][0];
            }
        }
        
        for(int i =0;i<a.size(); i++) {
            string p = find(a[i][1], parent);
            for(int j =2;j<a[i].size();j++) {
                parent[find(a[i][j], parent)] = p;
            }
        }
        
        for(int i =0;i<a.size();i++) {
            for(int j =1;j<a[i].size(); j++ ) {
                unions[find(a[i][j], parent)].insert(a[i][j]);
            }
        }
        
        vector<vector<string>> res;
        
        for(auto s : unions) {
            vector<string> email(s.second.begin(), s.second.end());
            email.insert(email.begin(), owner[s.first]);
            res.push_back(email);
        }
        return res;
    }
};