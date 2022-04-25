class Solution {
public:
    bool check(int i, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &dfsvis) {
        vis[i] = 1;
        dfsvis[i] = 1;
        for(auto it : adj[i]) {
            if(vis[it] == false) {
                if(check(it, adj, vis, dfsvis))
                    return true;
            } 
            else if(dfsvis[it] == true) {
                return true;
            }
        }
        dfsvis[i] = 0;
        return false;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        vector<bool> dfsvis(n, false);
        for(auto i : pre) {
            adj[i[0]].push_back(i[1]);
            
        }
        
        for(int i =0;i<n;i++) {
            if(vis[i] == false) {
                if(check(i,adj, vis, dfsvis)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};