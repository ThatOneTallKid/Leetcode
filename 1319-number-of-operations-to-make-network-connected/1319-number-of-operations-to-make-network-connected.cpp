class Solution {
public:
    void dfs( vector<vector<int>> &adj, int i , vector<bool> &vis) {
        vis[i] = true;
        for(auto node : adj[i]) {
            if(!vis[node]) {
                dfs(adj, node, vis);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int v = connections.size();
        if(n-1 > v) {
            return -1;
        }
        vector<bool> vis(n,0);
        vector<vector<int>> adj(n);
        for(auto c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        
        
        int count =0;
        for(int i =0;i<n;i++)
            if(vis[i] == false)
            {
                dfs(adj, i, vis);
                count++;
            }
        
        
        
        return count -1;
    }
};