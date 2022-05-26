class Solution {
public:
    // a simple solution is just finding the topological sort keeping cycle detection in mind.
    // but doing 2 dfs for both the topo and cycle detection can be costly.
    
    // so, the optimal approach is to take help from the devised topological sort vector/array.
    void topo(int node, vector<bool> &vis, stack<int> &st, vector<vector<int>> &adj) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                topo(it, vis, st, adj);
            }
        }
        st.push(node);
    }
    
    bool checkcycle(vector<vector<int>> &adj, int n, vector<int> &res) {
        unordered_map<int,int> pos;
        for(int i=0;i<res.size();i++) {
            pos[res[i]] = i;
        }
        // checking if there is a cycle with the help of the devised topological sort array.
        // if position of the child is before than that of the parent then cycle exists.
        for(int i =0;i<n;i++) {
            for(int v : adj[i]) {
                if(pos[v] < pos[i])
                    return true;
            }
        }
        return false;
    }
    
    
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        /*
            The key idea this question is to detect a cycle which will suggest if the topological sort of this graph is possible or not.
        */
        
        
        vector<vector<int>> adj(n);
        
        for(auto i : p){
            adj[i[1]].push_back(i[0]);
        }
        stack<int> st;
        vector<bool> vis(n, false);
        for(int i =0;i<n;i++) {
            if(vis[i] == false) {
                topo(i, vis, st, adj);
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        
        if(checkcycle(adj, n, res)){
            return {};
        }
        return res;
    }
};