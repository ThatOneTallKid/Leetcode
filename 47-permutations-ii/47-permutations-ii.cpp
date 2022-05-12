class Solution {
public:
    void backtrack(vector<int> nums, int index)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            if(nums[i] != nums[index])
            {
                swap(nums[i], nums[index]);
                backtrack(nums, index+1);
                
            }
            else if(i == index)
            {
                backtrack(nums, index+1);
            }
        }
    }
    
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }



    
};