class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs( path, 1 ,k, n);
        return res;
    }
    
    void dfs(vector<int> &path, int idx, int k, int n) {
        if(k == 0 and n == 0) {
            res.push_back(path);
            return;
        }
        
        for(int i = idx;i<=9;i++) {
            path.push_back(i);
            dfs(path, i+1,k-1, n-i);
            path.pop_back();
        }
    }
};