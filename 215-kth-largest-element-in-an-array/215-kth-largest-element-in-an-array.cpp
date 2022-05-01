class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*      priority queue sol   O(nlogn)     */
                priority_queue<int> pq;
        for(auto x : nums){
            pq.push(x);
        }
        
        int top;
        while(k--){
            top = pq.top();
            pq.pop();
        }
        return top;
        
        /*  
            approach 2 : sorting - O(nlogn)
            then get the element from behind
        */
        
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for (int num : nums) {
        //     pq.push(num);
        //     if (pq.size() > k) {
        //         pq.pop();
        //     }
        // }
        // return pq.top();
        
        
    }
};