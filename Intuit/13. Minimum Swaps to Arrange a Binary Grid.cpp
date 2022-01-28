class Solution {
   public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) {
                    break;
                }

                count++;
            }
            v.push_back(count);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int need = n - i - 1;
            int pos = -1;
            for (int j = i; j < n; j++) {
                if (v[j] >= need) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) {
                return -1;
            }

            for (int j = pos; j > i; j--) {
                swap(v[j], v[j - 1]);
                res++;
            }
        }

        return res;
    }
};