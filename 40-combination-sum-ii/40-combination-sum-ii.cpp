class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<int> path;
        sort(arr.begin(), arr.end());
        dfs(arr,path, 0, target);
        return res;
    }
    
    void dfs(vector<int> &arr, vector<int> &path, int idx, int target) {
        if(target == 0) {
            res.push_back(path);
            return;
        }
        
        for(int i = idx;i<arr.size();i++) {
            if(arr[i] > target) {
                return;
            }
            
            if(i > idx and arr[i] == arr[i - 1]) {
                continue;
            }
            
            path.push_back(arr[i]);
            dfs(arr, path, i+1, target - arr[i]);
            path.pop_back();
        }
    }
};