class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(res, path, 0, nums);
        return res;
    }
    
    void dfs(vector<vector<int>> &res, vector<int> &path, int i, vector<int> &nums) {
        
            res.push_back(path);
          
        
        for(int j = i;j<nums.size();j++) {
            if(i == j or nums[j] != nums[j-1]) {
                path.push_back(nums[j]);
                dfs(res, path, j+1, nums);
                path.pop_back();
            }
        }
    }
};