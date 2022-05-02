class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> P;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<arr.size();i++) pq.push({abs(arr[i]-x),arr[i]});
        while(k--){
            P.push_back(pq.top().second);
            pq.pop();
        }
        sort(P.begin(),P.end());
        return P;
    }
};