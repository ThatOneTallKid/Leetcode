class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int res = 0;
        for(int i =0;i<A.size();i++) {
            for(int j=1;j<A[0].size();j++) {
                A[i][j] += A[i][j-1];
            }
        }
        unordered_map<int, int> counter;
        for(int i =0;i<A[0].size();i++) {
            for(int j =i;j<A[0].size();j++) {
                int cur = 0;
                counter= {{0,1}};
                for(int k = 0;k<A.size();k++) {
                    cur += A[k][j] - (i > 0 ? A[k][i - 1] : 0);
                    res += (counter.find(cur-target) != counter.end()) ? counter[cur-target] : 0;
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};