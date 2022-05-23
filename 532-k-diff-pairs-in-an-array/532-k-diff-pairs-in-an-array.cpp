class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        set<pair<int,int>> st;
        int n = nums.size();
        for(int i =0;i<n;i++) {
            for(int j =i;j<n;j++) {
                if(abs(nums[i] - nums[j]) == k and i != j){
                    if(st.find({nums[i], nums[j]}) == st.end() or st.find({nums[j], nums[i]}) == st.end()) {
                        count++;
                        st.insert({nums[i], nums[j]});
                        st.insert({nums[j], nums[i]});
                    }
                    else {
                        continue;
                    }
                }
            }
        }
        return count;
    }
};