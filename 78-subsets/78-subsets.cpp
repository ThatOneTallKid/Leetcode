class Solution {
public:
    void dfs(vector<vector<int>> &res, vector<int> &nums, int i,vector<int> &path) {
        if(i == nums.size()){
            res.push_back(path);
            return;
        }
        
        
        
        path.push_back(nums[i]);
        dfs(res, nums,i+1, path);
        path.pop_back();
        dfs(res, nums,i+1, path);
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        
        dfs(res, nums, 0,path );
        return res;
    }
    
};