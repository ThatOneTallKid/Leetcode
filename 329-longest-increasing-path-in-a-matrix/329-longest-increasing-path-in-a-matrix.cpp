class Solution {
public:
    /*
        Brute force thinking:
        1. Do a dfs search for every pair of indices (i,j)
        2. go through all the 4 directions.
        3. get the longest path
        
        Problems: TC: O((n*m)*4^(n*m))
        
        
        Efficient approach
        1. use DP for storing previously calculated results.
    */
    
    vector<vector<int>> dp;
    int maxPath, n, m;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        maxPath = 0;
        dp.resize(n, vector<int> (m));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                maxPath = max(maxPath, solve(matrix, i, j, -1));
            }
        }
        
        return maxPath;
    }
    
    int solve(vector<vector<int>> &mat, int i, int j, int prev){
        if(i < 0 or j < 0 or i >= n or j >= m or mat[i][j] <= prev)
            return 0;
        if(dp[i][j])
            return dp[i][j];
        
        return dp[i][j] = 1 + max({ solve(mat, i, j+1, mat[i][j]), 
                                    solve(mat, i+1, j, mat[i][j]),
                                    solve(mat, i, j-1, mat[i][j]),
                                    solve(mat, i-1, j, mat[i][j]) });
        
    }
};