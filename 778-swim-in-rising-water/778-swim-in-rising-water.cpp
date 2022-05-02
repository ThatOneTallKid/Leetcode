class Solution {
public:
    int row[4]={1,-1,0,0};
int col[4]={0,0,1,-1};

int swimInWater(vector<vector<int>>& grid) {
    
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    pq.push({grid[0][0],{0,0}});
    int mx=0, m=grid.size(), n=grid[0].size();
    
    vector<vector<bool>> vec(m,vector<bool> (n,false));
    int t, x, y;
    while(!pq.empty()) {
        
        auto it = pq.top();
        t = it.first;
        x = it.second.first;
        y = it.second.second;
        vec[x][y]=true;
        
        pq.pop();
        mx=max(mx,t);
        
        if(x==m-1 && y==n-1)
            break;
        
        for(int i=0;i<4;i++) {
            int rr = x + row[i];
            int cc = y + col[i];
            
            if(rr>=0 && cc>=0 && rr<m && cc<n && !vec[rr][cc])
                pq.push({grid[rr][cc], {rr,cc}});
        }
    }
    return mx;
}
};