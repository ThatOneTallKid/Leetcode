class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        set<string> st;
        st.insert(s);
        for(int i =1;i<s.size();i++) {
            string x = s.substr(0,i);
            st.insert(x);
        }
        
        int count = 0;
        for(int i=0;i<words.size();i++) {
            if(st.find(words[i]) != st.end()) {
                count++;
            }
        }
        
        return count;
    }
};