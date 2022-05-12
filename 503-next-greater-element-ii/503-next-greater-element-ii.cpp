class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // nlogn can be achieved through sorting but O(n) will be expected in the interview.
        //circular integer array -> when we consider first element as the next of the last element hence it's circular 
        
        vector<int> ans(nums.size(), -1); // to store the next greater element of every element and initialize it with -1 why ? because if there is no element in stack which is greater to the element we will return -1
        
        stack<int> s; //make a stack 
        
        for(int i = 0; i < 2*nums.size()-1; i++) { //why ? 2*nums.size()-1 beacuse we assuming a joint imaginary array same as nums
            
            while(!s.empty() && nums[s.top()] < nums[i%nums.size()]) {
                //check  if the stack is not empty  and the check the top element of the stack if there is an element present which is smaller than i% nums.size
                ans[s.top()] = nums[i%nums.size()];
                s.pop();// pop the elements which are smaller 
            }
            s.push(i%nums.size()); 
        }
        return ans;
    }
};