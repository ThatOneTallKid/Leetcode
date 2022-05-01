class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //  unordered_map<char, int> counts;
        // for (char t : tasks) {
        //     counts[t]++;
        // }
        // priority_queue<int> pq;
        // for (pair<char, int> count : counts) {
        //     pq.push(count.second);
        // }
        // int alltime = 0;
        // int cycle = n + 1;
        // while (!pq.empty()) {
        //     int time = 0;
        //     vector<int> tmp;
        //     for (int i = 0; i < cycle; i++) {
        //         if (!pq.empty()) {
        //             tmp.push_back(pq.top());
        //             pq.pop();
        //             time++;
        //         }
        //     }
        //     for (int cnt : tmp) {
        //         if (--cnt) {
        //             pq.push(cnt);
        //         }
        //     }
        //     alltime += !pq.empty() ? cycle : time;
        // }
        // return alltime;
        
        unordered_map<char,int> mp;
        int max_cnt = 0;
        for(auto i : tasks) {
            mp[i]++;
            max_cnt = max(max_cnt, mp[i]);
        }
        
        int ans = (max_cnt - 1)* (n+1);
        for(auto i : mp) {
            if(i.second == max_cnt)
                ans++;
        }
        
        return max((int)tasks.size(), ans);
    }
};