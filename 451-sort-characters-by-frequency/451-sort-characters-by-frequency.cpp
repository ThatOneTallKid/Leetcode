class Solution {
public:
    string frequencySort(string s) {
         string ans= "";
        map<char,int> mp;
        priority_queue<pair<int,int> , vector<pair<int,int>> >  pq;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        map<char,int> :: iterator it;
        for(it=mp.begin();it !=mp.end(); it++)
        {
           pq.push({it->second,it->first}); 
        }
        while(!pq.empty())
        {
            pair<int,int> x=pq.top();
            pq.pop();
            while(x.first--)
            ans += x.second;
            
            
        }
        return ans;
    }
};