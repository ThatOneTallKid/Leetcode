class Solution {
public:
    // int largestRectangleArea(vector<int>& height) {
    //     height.push_back(0);
    //     const int size_h = height.size();
    //     stack<int> stk;
    //     int i = 0, max_a = 0;
    //     while (i < size_h) {
    //         if (stk.empty() || height[i] >= height[stk.top()]) 
    //             stk.push(i++);
    //         else {
    //             int h = stk.top();
    //             stk.pop();
    //             max_a = max(max_a, height[h] * (stk.empty() ? i : i - stk.top() - 1));
    //         }
    //     }
    //     return max_a;
    // }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0)
            return 0;
        
        stack<int> S;
        
        int L[n];
        int R[n];
        
        for(int i=0; i<n; i++) {
            while(!S.empty() && heights[S.top()] >= heights[i]) 
                S.pop();
            
            L[i] = S.empty() ? -1 : S.top();
            S.push(i);
        }
        
        while(!S.empty()) S.pop();
        
        for(int i=n-1; i>=0; i--) {
            while(!S.empty() && heights[S.top()] >= heights[i])
                S.pop();
            
            R[i] = S.empty() ? n : S.top();
            S.push(i);
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
        //cout << L[i] << " "<< R[i] <<endl;
            ans = max(ans, (R[i]-L[i]-1) * heights[i]);
        }
        
        return ans;
    }
};

// more sensible solution

/*
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0)
            return 0;
        
        stack<int> S;
        
        int L[n];
        int R[n];
        
        for(int i=0; i<n; i++) {
            while(!S.empty() && heights[S.top()] >= heights[i]) 
                S.pop();
            
            L[i] = S.empty() ? -1 : S.top();
            S.push(i);
        }
        
        while(!S.empty()) S.pop();
        
        for(int i=n-1; i>=0; i--) {
            while(!S.empty() && heights[S.top()] >= heights[i])
                S.pop();
            
            R[i] = S.empty() ? n : S.top();
            S.push(i);
        }
        
        int ans = 0;
        
        for(int i=0; i<n; i++) {
        cout << L[i] << " "<< R[i] <<endl;
            ans = max(ans, (R[i]-L[i]-1) * heights[i]);
        }
        
        return ans;
    }
*/