// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> A, int x, int y) {
        // code here
        queue<pair<int,int>> q;
        q.push({0,0});
        if(A[0][0]==0)
        return -1;
        vector<vector<int>> vis(n,vector<int> (m,0));
        int ans=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {int i=q.front().first;
            int j=q.front().second;q.pop();
            if(x==i&&j==y)
            return ans;
            if(i-1>=0&&vis[i-1][j]!=1&&A[i-1][j]==1)
            {
                vis[i-1][j]=1;
                q.push({i-1,j});
            }
            if(i+1<n&&vis[i+1][j]!=1&&A[i+1][j]==1)
            {
                vis[i+1][j]=1;
                q.push({i+1,j});
            }
            if(j-1>=0&&vis[i][j-1]!=1&&A[i][j-1]==1)
            {
                vis[i][j-1]=1;
                q.push({i,j-1});
            }
            if(j+1<m&&vis[i][j+1]!=1&&A[i][j+1]==1)
            {
                vis[i][j+1]=1;
                q.push({i,j+1});
            }}
            ans++;
        }
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends