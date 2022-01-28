class Solution {
   public:
    Node* solve(int i, int j, int sz, vector<vector<int>>& grid) {
        if (sz == 1) {
            return new Node(grid[i][j], true);
        }

        bool same = true;
        for (int x = i; x < i + sz; x++) {
            for (int y = j; y < j + sz; y++) {
                if (grid[x][y] != grid[i][j]) {
                    same = false;
                }
            }
        }

        Node* curr = new Node(same == true ? grid[i][j] : 1, same);
        if (!same) {
            sz = sz / 2;
            curr->topLeft = solve(i, j, sz, grid);
            curr->topRight = solve(i, j + sz, sz, grid);
            curr->bottomLeft = solve(i + sz, j, sz, grid);
            curr->bottomRight = solve(i + sz, j + sz, sz, grid);
        }

        return curr;
    }

    Node* construct(vector<vector<int>>& grid) {
        return solve(0, 0, grid.size(), grid);
    }
};