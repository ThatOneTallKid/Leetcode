class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid) {
        if(i< 0 or j < 0 or i >= n or j >= m or grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '#';
        dfs(i-1,j, n,m, grid);
        dfs(i+1,j, n,m, grid);
        dfs(i,j-1, n,m, grid);
        dfs(i,j+1, n,m, grid);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i =0;i<n;i++) {
            for(int j =0;j < m;j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        
        return count;
    }
};