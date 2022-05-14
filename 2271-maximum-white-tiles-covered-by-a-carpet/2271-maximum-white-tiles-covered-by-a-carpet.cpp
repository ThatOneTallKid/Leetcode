class Solution {
public:
    int bigetCorr(int& i, vector<vector<int>>& tiles, int& carpetLen, int& target){
        int l = i, r = tiles.size()-1, res;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(tiles[mid][1] == target)
                return mid;
            else if(tiles[mid][1] < target){
                l = mid + 1;
            }
            else{
                res = mid;
                r = mid - 1;
            }
        }
        return res;
    }
    
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int ans = INT_MIN;
        sort(tiles.begin(), tiles.end());
        vector<int> hole = {0};
        for(int i=1; i<tiles.size(); i++)
            hole.push_back(tiles[i][0] - tiles[i-1][1] - 1 + hole.back());
  
		 // carpet length longer than the whole tiles
        if(carpetLen >= tiles.back()[1] - tiles[0][0] + 1)
            return tiles.back()[1] - tiles[0][0] + 1 - hole.back();
        
        for(int i=0; i<tiles.size()-1; i++){
            int target = min(tiles.back()[1], tiles[i][0] + carpetLen - 1), len = target - tiles[i][0] + 1;
            int j = bigetCorr(i, tiles, carpetLen, target);
            
            // i+1 ~ j presum
            if(tiles[j][0] > target)
                ans = max(ans, len - (target - tiles[j-1][1] + hole[j-1] - hole[i]));
            else
                ans = max(ans, len - (hole[j] - hole[i]));
            
        }
        return max(ans, tiles.back()[1] - tiles.back()[0] + 1);
    }
};