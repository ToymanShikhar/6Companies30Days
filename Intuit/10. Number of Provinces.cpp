class Solution {
   public:
    void dfs(int src, vector<vector<int>>& edges, vector<bool>& visited, int n) {
        visited[src] = true;

        for (int i = 0; i < n; i++) {
            if (edges[src][i] == 1 and !visited[i]) {
                dfs(i, edges, visited, n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res++;
                dfs(i, edges, visited, n);
            }
        }
        return res;
    }
};