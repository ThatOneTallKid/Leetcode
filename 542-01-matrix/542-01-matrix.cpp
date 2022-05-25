class Solution {
public:
   
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxdist = m+n;
        queue<pair<int,int>> q;
        for(int i =0;i<m;i++) 
            for(int j =0;j<n;j++)
                matrix[i][j] == 0 ? q.push({i,j}) : (void) (matrix[i][j] = maxdist);
        
        int delta[4][2] = {-1, 0, 1, 0,0,-1,0,1};
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(int i =0;i<4;i++) {
                int x1 = x + delta[i][0];
                int y1 = y + delta[i][1];
                if(0 <= x1 and x1 < m and 0 <= y1 and y1 < n) {
                    if(matrix[x1][y1] == maxdist)
                        q.push({x1, y1});
                    matrix[x1][y1] = min(matrix[x1][y1], matrix[x][y] + 1);
                }
            }
        }
        
        return matrix;
    }
};