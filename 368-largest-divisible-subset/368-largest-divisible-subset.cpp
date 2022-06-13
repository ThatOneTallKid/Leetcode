class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> divCount(n, 1);
        vector<int> prev(n, -1);
        int max_id = 0;
        for (int i = 1; i < n;i++) {
            for (int j = 0; j < i;j++) {
                if(arr[i] %arr[j] == 0){
                    if(divCount[i] < divCount[j] + 1) {
                        divCount[i] = divCount[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if(divCount[max_id] < divCount[i]){
                max_id = i;
            }
        }
        vector<int> res;
        int k = max_id;
        while(k>=0) {
            res.push_back(arr[k]);
            k = prev[k];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};