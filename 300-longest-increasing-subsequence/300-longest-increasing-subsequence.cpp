class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> lis(n);
        // lis[0] = 1;
        // for(int i =1;i<n;i++) {
        //     lis[i] = 1;
        //     for(int j =0;j<i;j++) {
        //         if(nums[i] > nums[j] and lis[i] < lis[j] + 1) {
        //             lis[i] = lis[j] + 1;
        //         }
        //     }
        // }
        // return *max_element(lis.begin(), lis.end());
        
        
        // nlogn
        
        vector<int> lis;
        lis.push_back(nums[0]);
        int n = nums.size();
        for(int i =1;i<n;i++) {
            if(lis.back() < nums[i]) {
                lis.push_back(nums[i]);
            }
            else {
                int idx = lower_bound(lis.begin(),lis.end() , nums[i]) - lis.begin();
                lis[idx] = nums[i];
            }
        }
        return lis.size();
    }
};