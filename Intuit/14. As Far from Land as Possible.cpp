class Solution {
   public:
    vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        if (q.size() == (n * n)) {
            return -1;
        }

        int res = -1;
        while (!q.empty()) {
            int sz = q.size();
            res++;
            while (sz--) {
                pair<int, int> t = q.front();
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nexti = t.first + dir[k].first;
                    int nextj = t.second + dir[k].second;

                    if (nexti >= 0 and nexti < n and nextj >= 0 and nextj < n and grid[nexti][nextj] == 0) {
                        grid[nexti][nextj] = 1;
                        q.push({nexti, nextj});
                    }
                }
            }
        }

        return res;
    }
};