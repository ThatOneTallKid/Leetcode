class Solution {
public:
    void DFS(vector<vector<char>> &a, int i, int j, int m, int n) {
        if(i < 0 or j < 0 or i >= m or j >= n or a[i][j] != 'O')
            return;
        a[i][j] = '#';
        DFS(a,i+1, j, m, n);
        DFS(a,i-1, j, m, n);
        DFS(a,i, j+1, m, n);
        DFS(a,i, j-1, m, n);
    
    }
    
    void solve(vector<vector<char>>& a) {
        int m = a.size();
        int n = a[0].size();
        if(m == 0) {
            return;
        }
        //Steps to Solve :
      //1. Move over the boundary of board, and find O's 
      //2. Every time we find an O, perform DFS from it's position
      //3. In DFS convert all 'O' to '#'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
      //4. After all DFSs have been performed, board contains three elements,#,O and X
      //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      //6. '#' are elements which cannot be flipped to 'X', so flip them back to 'O'
      //7. finally, Upvote the solution\U0001f60a   
        
        for(int i =0;i<m;i++) {
            if(a[i][0] == 'O')
                DFS(a, i, 0, m, n);
            if(a[i][n-1] == 'O')
                DFS(a, i, n-1, m , n);
        }
        
        for(int j = 0;j<n;j++) {
            if(a[0][j] == 'O')
                DFS(a, 0,j,m,n);
            if(a[m-1][j] == 'O')
                DFS(a, m-1,j,m,n);
        }
        
        for(int i =0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(a[i][j] == 'O')
                    a[i][j] = 'X';
                if(a[i][j] == '#')
                    a[i][j] = 'O';
            }
        }
        
    }
};