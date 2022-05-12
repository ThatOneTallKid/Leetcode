class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        vector<int> path;
        dfs(arr, path, 0, target);
        return res;
    }
    
    void dfs(vector<int> &arr, vector<int> &path, int i, int target) {
        if(target == 0) {
            res.push_back(path);
            return;
        }
        
        for(int j =i;j<arr.size();j++) {
            if(arr[j] > target) {
                return;
            }
            
            path.push_back(arr[j]);
            dfs(arr, path,j, target- arr[j]);
            path.pop_back();
        }
    }
};