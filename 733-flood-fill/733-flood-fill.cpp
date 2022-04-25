class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor)
            dfs(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
    
    void dfs(vector<vector<int >> &image, int i, int j, int c0, int c1) {
        if(i < 0 or j < 0 or i >= image.size() or j >= image[0].size() or image[i][j] != c0) 
            return;
        
        image[i][j] = c1;
        dfs(image, i, j-1, c0, c1);
        dfs(image, i, j + 1, c0, c1);
        dfs(image, i-1, j, c0, c1);
        dfs(image, i+1, j, c0, c1);
    }
};