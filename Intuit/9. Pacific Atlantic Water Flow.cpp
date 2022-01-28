class Solution {
   public:
    vector<pair<int, int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(int i, int j, int& rows, int& cols, int prev, vector<vector<int>>& grid, vector<vector<bool>>& ocean) {
        if (i < 0 or j < 0 or i >= rows or j >= cols or ocean[i][j] or grid[i][j] < prev) {
            return;
        }

        ocean[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int nextI = i + dir[k].first;
            int nextJ = j + dir[k].second;
            dfs(nextI, nextJ, rows, cols, grid[i][j], grid, ocean);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        //dfs
        for (int i = 0; i < cols; i++) {
            dfs(0, i, rows, cols, INT_MIN, heights, pacific);
            dfs(rows - 1, i, rows, cols, INT_MIN, heights, atlantic);
        }
        for (int i = 0; i < rows; i++) {
            dfs(i, 0, rows, cols, INT_MIN, heights, pacific);
            dfs(i, cols - 1, rows, cols, INT_MIN, heights, atlantic);
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] and atlantic[i][j]) {
                    res.push_back(vector<int>{i, j});
                }
            }
        }

        return res;
    }
};