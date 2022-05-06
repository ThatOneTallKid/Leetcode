class Solution {
public:
    string removeDuplicates(string S, int K) {
        int i, j;
        stack<int> st;
        st.push(0);
        for (i = 1, j = 1; j < S.size(); i++, j++) {
            S[i] = S[j];
            if (i == 0 || S[i] != S[i-1]) st.push(i);
            else if (i - st.top() + 1 == K) {
                i = st.top() - 1;
                st.pop();
            }
        }
        return S.substr(0, i);
    }
};