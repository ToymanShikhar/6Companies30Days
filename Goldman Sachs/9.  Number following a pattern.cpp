class Solution {
   public:
    string printMinNumberForPattern(string S) {
        stack<int> st;
        string res;
        int curr = 1;

        for (int i = 0; i < S.length(); i++) {
            st.push(curr);
            curr++;
            if (S[i] == 'I') {
                while (!st.empty()) {
                    res += to_string(st.top());
                    st.pop();
                }
            }
        }

        st.push(curr);
        while (!st.empty()) {
            res += to_string(st.top());
            st.pop();
        }

        return res;
    }
};