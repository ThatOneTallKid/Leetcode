class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> vec(k);
        unordered_map<int,set<int>> user_log;
        for(auto usr : logs) {
            user_log[usr[0]].insert(usr[1]);
        }
        
        for(auto i: user_log) {
            if(i.second.size() > 0) {
                vec[i.second.size() - 1]++;
            }
        }
        
        return vec;
    }
};