class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long int res = INT_MAX;
        vector<long long int> pre(n,0);
        pre[0] = nums[0];
        for(int i =1;i < n;i++) {
            pre[i] = nums[i] + pre[i-1];
            
        }
        int idx = 0;
        for(int i =0;i<n;i++) {
            long long int left = pre[i]/(i+1);
            long long int right = 0;
            if(i != n-1) {
                right = (pre[n-1] - pre[i])/(n-i-1);
            }
            
            
            long long int diff = abs(left - right);
            //cout << left << " " << right;
            //cout << i << " " << diff << endl;
            if(res > diff) {
                res = diff;
                idx = i;
            }
        }
        return idx;
    }
};