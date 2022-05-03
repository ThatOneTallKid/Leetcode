class Solution {
public:
    int totalFruit(vector<int>& a) {
        vector<int> freq(a.size(),0);
        int i =0;
        int res = 0;
        int distinct = 0;
        for(int j = 0;j<a.size();j++) {
            freq[a[j]]++;
            if(freq[a[j]] == 1)
                distinct++;
            
            if(distinct <= 2) {
                res = max(res, j - i + 1);
            }
            
            if(distinct > 2 and i < j) {
                freq[a[i]]--;
                if(freq[a[i]] == 0)
                    distinct--;
                i++;
            }
        }
        
        return res;
    }
};