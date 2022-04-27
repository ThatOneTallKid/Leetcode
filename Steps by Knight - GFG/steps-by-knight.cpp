// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&kni,vector<int>&tar,int n)
	{
	    // Code here
	    int mat[n+1][n+1] = {0};
	    pair<int, int> p;
	    queue<pair<int, int> > q; 
	    
	    q.push({kni[0], kni[1]});
	    int sum = 0;
	    mat[kni[0]][kni[1]] = 0;
	    
	    while(!q.empty()){
	        
	        p = q.front();
	        q.pop();
	        int a = p.first;
	        int b = p.second;
	        sum = mat[a][b]+1;
	        
	        if(a==tar[0] && tar[1]==b)
	            break;
	        if(a+1<=n && b-2>0 && mat[a+1][b-2]==0){
	            q.push({a+1, b-2});
	            mat[a+1][b-2] = sum;
	        }
	        if(a-1>0 && b-2>0 && mat[a-1][b-2]==0){
	            q.push({a-1, b-2});
	            mat[a-1][b-2] = sum;
	        }
	        
	        if(a+1<=n && b+2<=n && mat[a+1][b+2]==0){
	            q.push({a+1, b+2});
	            mat[a+1][b+2] = sum;
	        }
	        if(a-1>0 && b+2<=n && mat[a-1][b+2]==0){
	            q.push({a-1, b+2});
	            mat[a-1][b+2] = sum;
	        }
	        
	        
	        if(a-2>0 && b-1>0 && mat[a-2][b-1]==0){
	            q.push({a-2, b-1});
	            mat[a-2][b-1] = sum;
	        }
	        if(a-2>0 && b+1<=n && mat[a-2][b+1]==0){
	            q.push({a-2, b+1});
	            mat[a-2][b+1] = sum;
	        }
	        if(a+2<=n && b-1>0 && mat[a+2][b-1]==0){
	            q.push({a+2, b-1});
	            mat[a+2][b-1] = sum;
	        }
	        if(a+2<=n && b+1<=n && mat[a+2][b+1]==0){
	            q.push({a+2, b+1});
	            mat[a+2][b+1] = sum;
	        }
	    }
	    
	    return sum-1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends