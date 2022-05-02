class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i =0;
        int n = heights.size();
        int jump = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        while(i < n-1 and size(pq) < ladders) {
            jump = heights[i+1] - heights[i];
            if(jump > 0) {
            pq.push(jump);
            }
            i++;
        }
        
        while(i < n -1) {
            jump = heights[i+1] - heights[i];
            if(jump > 0) {
                if(!pq.empty() and pq.top() < jump) {
                    bricks -= pq.top();
                    pq.pop();
                    pq.push(jump);
                }
                else {
                    bricks -= jump;
                }                
            }
            if(bricks < 0)
                return i;
            i++;
        }
        return i;
    }
        
    
};