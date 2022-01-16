class Solution {
   public:
    int solve(int i, int j, int rows, int cols, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        if (i < 0 or i >= rows or j < 0 or j >= cols or grid[i][j] == 0 or visited[i][j] == 1) {
            return 0;
        }

        visited[i][j] = 1;
        int tempAns = 0;
        vector<pair<int, int>> sides{{1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}};
        for (auto p : sides) {
            int nextRow = i + p.first;
            int nextCol = j + p.second;
            tempAns += solve(nextRow, nextCol, rows, cols, grid, visited);
        }

        return 1 + tempAns;
    }

    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int tempAns = solve(i, j, n, m, grid, visited);
                ans = max(ans, tempAns);
            }
        }

        return ans;
    }
};