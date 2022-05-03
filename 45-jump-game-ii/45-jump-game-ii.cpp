class Solution {
public:
    
    int min_jumps(vector<int> &nums, int n, vector<int> &dp, int i ) {
       if(i==n-1)
           return 0;
        if(i>=n) {
            return INT_MAX;
        }
        if(dp[i]!=0)
            return dp[i];
        
        int steps = INT_MAX;
        int limit = nums[i];
        for(int j = 1;j<=limit;j++) {
            int next = i+j;
            int sub = min_jumps(nums, n, dp, next);
            if(sub != INT_MAX) {
                steps = min(sub+1, steps);
            }
        }
        return dp[i] = steps;
    }
    
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        return min_jumps(nums, n, dp, 0);
    }
};