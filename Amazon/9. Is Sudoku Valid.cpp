class Solution {
   public:
    int isValid(vector<vector<int>> mat) {
        unordered_set<string> st;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (mat[i][j] != 0) {
                    string k1 = to_string(mat[i][j]) + "inrow" + to_string(i);
                    string k2 = to_string(mat[i][j]) + "incol" + to_string(j);
                    string k3 = to_string(mat[i][j]) + "ingrid" + to_string(i / 3) + to_string(j / 3);
                    ;

                    if (st.find(k1) != st.end() or st.find(k2) != st.end() or st.find(k3) != st.end()) {
                        return false;
                    }

                    st.insert(k1);
                    st.insert(k2);
                    st.insert(k3);
                }
            }
        }

        return true;
    }
};