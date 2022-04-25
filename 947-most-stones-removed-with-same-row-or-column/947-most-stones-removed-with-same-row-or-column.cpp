class Solution {
public:
    /*
    The idea is to just count the number of nodes that can be visited from a particular node through a dfs.
    ```
        (stones[i][0] == stones[idx][0] or stones[i][1] == stones[idx][1])
    ```
    */
    int dfs(vector<vector<int>> &stones, int idx, vector<bool> &vis, int &n) {
        vis[idx] = true;
        int res = 0;
        for(int i =0;i<n;i++) {
            if(vis[i] == false and (stones[i][0] == stones[idx][0] or stones[i][1] == stones[idx][1]))
                res += dfs(stones, i, vis, n) + 1;
        }
        return res;
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> vis(n,0);
        int res = 0;
        for(int i =0;i<n;i++) {
            if(!vis[i]) {
                res += dfs(stones, i, vis, n);
            }
        }
        return res;
    }
};