class Solution {
public:
    int dp[31][1001];
    int solve(int d, int f, int t){
        // if d=0 and t=0 means we have left with 0 sum and no dice so return 1
        if(d==0 and t==0) return 1;
		
		// if dice are left but sum is 0 or sum dice are 0 and sum is greater than 0 then we dont have any way so return 0
        if(d==0 or t==0) return 0;
		
		// return if we have calculated it before
        if(dp[d][t]!=-1) return dp[d][t];
		
		// else calculate it current dice can have any value between 1 and f so consider all cases
        long long res=0;
        for(int i=1;i<=f;i++){
            if(i<=t) 
                res+=solve(d-1,f,t-i);
        }
        // return answer
        return dp[d][t] = res%1000000007;
    }
    
    
    int numRollsToTarget(int d, int f, int t) {
        memset(dp,-1,sizeof(dp));
        return solve(d,f,t);
    }
};



/*

int dp[31][1001];
    int solve(int d, int f, int t){
        // if d=0 and t=0 means we have left with 0 sum and no dice so return 1
        if(d==0 and t==0) return 1;
		
		// if dice are left but sum is 0 or sum dice are 0 and sum is greater than 0 then we dont have any way so return 0
        if(d==0 or t==0) return 0;
		
		// return if we have calculated it before
        if(dp[d][t]!=-1) return dp[d][t];
		
		// else calculate it current dice can have any value between 1 and f so consider all cases
        long long res=0;
        for(int i=1;i<=f;i++){
            if(i<=t) res+=solve(d-1,f,t-i);
        }
        // return answer
        return dp[d][t] = res%1000000007;
    }
    
    
    int numRollsToTarget(int d, int f, int t) {
        memset(dp,-1,sizeof(dp));
        return solve(d,f,t);
    }

*/