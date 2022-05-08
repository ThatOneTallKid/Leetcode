// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int knapsack(int price[], int lenght[], int n, int max_len) {
        int dp[n+1][max_len+1];
        for(int i =0;i<n+1;i++) {
            for(int j = 0;j<max_len+1;j++) {
                if(i ==0 or j == 0)
                    dp[i][j] = 0;
            }
        }
        
        
        for(int i =1;i<=n;i++) {
            for(int j =1;j<=max_len;j++){
                if(lenght[i-1] <= j) {
                    dp[i][j] = max(price[i-1] + dp[i][j- lenght[i-1]], dp[i-1][j]);
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][max_len];
    }
    
    int cutRod(int price[], int n) {
        //code here
        int lenght[n];
        for(int i =0;i<n;i++) {
            lenght[i] = i+1;
        }
        int max_len = n;
        return knapsack(price, lenght, n , max_len);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends