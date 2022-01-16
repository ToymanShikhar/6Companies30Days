class Solution {
   public:
    void dfs(int src, vector<int>& visited, string& res, vector<vector<int>>& graph) {
        visited[src] = 1;
        for (auto x : graph[src]) {
            if (!visited[x]) {
                dfs(x, visited, res, graph);
            }
        }

        char ch = 'a' + src;
        res = ch + res;
    }

    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> graph(K);
        for (int i = 0; i < N - 1; i++) {
            string w1 = dict[i];
            string w2 = dict[i + 1];

            for (int j = 0; j < min(w1.length(), w2.length()); j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j] - 'a'].push_back(w2[j] - 'a');
                    break;
                }
            }
        }

        string res;
        vector<int> visited(K, 0);
        for (int i = 0; i < K; i++) {
            if (!visited[i]) {
                dfs(i, visited, res, graph);
            }
        }

        return res;
    }
};