class Solution {
   public:
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
        int rs = 0;
        int re = r - 1;
        int cs = 0;
        int ce = c - 1;
        vector<int> res;

        while (rs <= re or cs <= ce) {
            if (rs <= re) {
                for (int i = cs; i <= ce; i++) {
                    res.push_back(matrix[rs][i]);
                }
                rs++;
            }

            if (cs <= ce) {
                for (int i = rs; i <= re; i++) {
                    res.push_back(matrix[i][ce]);
                }
                ce--;
            }

            if (rs <= re) {
                for (int i = ce; i >= cs; i--) {
                    res.push_back(matrix[re][i]);
                }
                re--;
            }

            if (cs <= ce) {
                for (int i = re; i >= rs; i--) {
                    res.push_back(matrix[i][cs]);
                }
                cs++;
            }
        }
        return res;
    }
};