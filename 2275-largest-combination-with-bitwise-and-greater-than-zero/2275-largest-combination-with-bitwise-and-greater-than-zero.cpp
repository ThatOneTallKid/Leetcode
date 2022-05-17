class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi=0;
        for(int i=0;i<30;i++){
            int c=0;
            for(int x : candidates) if((x>>i&1)==1) c++;
            maxi = max(maxi,c);
        }
        return maxi;
    }
};