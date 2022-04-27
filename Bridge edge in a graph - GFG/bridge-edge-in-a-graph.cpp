// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	vector<int> low, tin,vis;
	vector<vector<int>> res;
	int timer = 0;
	bool check = false;
	void dfs(vector<int> adj[], int node, int parent, int c, int d) {
	    low[node] = tin[node] = timer++;
	    vis[node] = true;
	    
	    for(auto &it : adj[node]) {
	        if(parent == it){
	            continue;
	        }
	        if(vis[it] == false) {
	            dfs(adj,it,node,c,d);
	            low[node] = min(low[node], low[it]);
	            if(low[it] > tin[node]) {
	                if(it == c and node == d or (it == d and node == c)) {
	                    check = true;
	                    return;
	                } 
	            }
	            
	        }
	        else {
	                low[node] = min(tin[it], low[node]);
	            }
	    }
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int n, vector<int> adj[], int c, int d) 
    {
        // Code here
        vis.resize(n, false);
        low.resize(n,0);
        tin.resize(n,0);
        for(int i =0;i<n;i++) {
            if(!vis[i])
                dfs(adj,i,i,c,d);
        }
        
        
        return check;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends