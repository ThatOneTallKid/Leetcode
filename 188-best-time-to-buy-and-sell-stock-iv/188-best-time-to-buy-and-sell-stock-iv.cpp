class Solution {
public:
    
    
    
     int solve(int i,bool own,int k,vector<int>& prices,vector<vector<vector<int>>> &dp)
    {
        if(i >= prices.size() or k <= 0)
        {
            return 0;
        }
        
        if(dp[i][own][k] != -1)
        {
            return dp[i][own][k];
        }
        
		// We own Stock --> Sell
        if(own)
        {
            int op1 = prices[i] + solve(i+1,0,k-1,prices,dp);
            int op2 = solve(i+1,1,k,prices,dp);
            
            return dp[i][own][k] = max(op1,op2);
                
        }
		
		//We have to buy a Stock
        else
        {
            int op1 = -prices[i] + solve(i+1,1,k,prices,dp);
            int op2 = solve(i+1,0,k,prices,dp);
            
            return dp[i][own][k] = max(op1,op2);
            
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solve(0,0,k,prices,dp);
        
        vector<int> buy(k+1, INT_MIN), sell(k+1, 0);
        
        for(int i=0; i<n; i++){
				for(int j=1; j<=k; j++){
					buy[j] = max(buy[j], sell[j-1]-prices[i]);
					sell[j] = max(sell[j], buy[j]+prices[i]);
				}
			} 
		return sell[k];
    }
};