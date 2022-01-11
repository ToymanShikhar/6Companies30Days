class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int ans = -1;
        int row = grid.size();
        int col = grid[0].size();
        vector<int> nxt{0, 1, 0, -1, 0};

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            int sz = q.size();
            ans++;
            while (sz--) {
                pair<int, int> t = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int r = t.first + nxt[i];
                    int c = t.second + nxt[i + 1];
                    if (r >= 0 and r < row and c >= 0 and c < col) {
                        if (grid[r][c] == 1) {
                            grid[r][c] = 2;
                            q.push({r, c});
                            fresh--;
                        }
                    }
                }
            }
        }

        if (fresh > 0) {
            return -1;
        }
        if (ans == -1) {
            return 0;
        }
        return ans;
    }
};