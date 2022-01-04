class Solution {
   public:
    string decodedString(string s) {
        stack<char> st;
        string res;

        for (int i = 0; i < s.length(); i++) {
            st.push(s[i]);

            if (s[i] == ']') {
                string tempAns;
                st.pop();
                while (st.top() != '[') {
                    char ch = st.top();
                    st.pop();
                    tempAns = ch + tempAns;
                }
                st.pop();

                char n = st.top();
                string num;
                while (n >= '0' and n <= '9') {
                    num = n + num;
                    st.pop();
                    if (st.empty()) {
                        n = '.';
                    } else {
                        n = st.top();
                    }
                }
                stringstream ss(num);
                int times;
                ss >> times;

                string temp = tempAns;
                for (int j = 2; j <= times; j++) {
                    tempAns += temp;
                }

                for (auto x : tempAns) {
                    st.push(x);
                }
            }
        }

        while (!st.empty()) {
            char ch = st.top();
            st.pop();
            res = ch + res;
        }

        return res;
    }
};