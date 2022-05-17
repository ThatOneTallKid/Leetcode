class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        int n = t.size();
        vector<int> res(t.size(),0);
        for(int i =n-1;i>=0;i--) {
            while(st.size() and t[st.top()] <= t[i])
                st.pop();
            res[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return res;
        
    }
};