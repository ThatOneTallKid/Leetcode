// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int color[100000] = {};
    bool explore(vector<int> adj[], int node, bool isA = true) {
        color[node] = isA ? 1 : -1;
        for(int it : adj[node]) {
            if(color[it]) {
                if(color[it] == (isA ? 1 : -1)){
                    return false;
                }
            }
            else {
                if(!explore(adj,it,!isA)) {
                    return false;
                }
            }
        }
        return true;
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    for(int i = 0;i<V;i++) {
	        if(!color[i] and !explore(adj,i)) {
	            return false;
	        }
	    }
	    
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends