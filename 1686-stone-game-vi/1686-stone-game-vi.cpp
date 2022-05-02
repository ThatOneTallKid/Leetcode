class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        priority_queue<pair<int, pair<int,int>>> pq;
        
        int alice=0, bob=0;
        
        for(int i=0; i<a.size(); i++){
            pq.push({a[i]+b[i], {a[i], b[i]}});
        }
        
        while(pq.size()){
            alice += pq.top().second.first; pq.pop();
            if(pq.size()) bob += pq.top().second.second, pq.pop();
        }
        
        if(bob == alice) return 0;
        if(bob > alice) return -1;
        return 1;
    }
};