class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int n = special.size();
        sort(special.begin(), special.end());
        int max_floor = INT_MIN;
        max_floor = max(max_floor, special[0] - bottom);
        max_floor = max(max_floor, top - special[n-1]);
        for(int i = 1;i<n;i++) {
            max_floor = max(max_floor, special[i] - special[i-1] -1);
        }
        
        return max_floor;
    }
};