class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // same as coin change with max number of ways - easy peasy
        // this particular solution is in 1D DP 
        // a 2D dp solution also exist
        
        vector<unsigned int> dp(target+1,0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int n : nums) {
                if (i >= n) {
                    dp[i] += dp[i - n];
                }
            }
        }
        return dp[target];
    }
};