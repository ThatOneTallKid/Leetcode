class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
//         int n=M.size(),ans=0;
// 	if(n==0) return 0;

// 	vector<bool>vis(n,false);

// 	for(int i=0;i<n;i++)
// 	{
// 		if(!vis[i])
// 		{
// 			ans++;
// 			dfs(M,vis,i);
// 		}
// 	}
// 	return ans;
        
        // dsu union find
        int n = M.size();
        if(M.empty())
            return 0;
        
        vector<int> parent(n,0);
        for(int i =0;i<n;i++)
            parent[i] = i;
        int groups = n;
        for(int i =0;i<n;i++) {
            for(int j =i+1;j<n;j++) {
                if(M[i][j]) {
                    int x = find(i, parent);
                    int y = find(j, parent);
                    if(x != y) {
                        parent[x] = y;
                        groups--;
                    }
                }
            }
        }
        
        return groups;
        
    }
    
    int find(int x, vector<int> &parent) {
        return parent[x] == x ? x : find(parent[x], parent);
    }
    
    void dfs(vector<vector<int>>& M, vector<bool>& vis, int i)
{
	vis[i]=true;
	for(int j=0;j<M.size();j++)
		if(M[i][j]==1 && !vis[j])
			dfs(M,vis,j);
}
};