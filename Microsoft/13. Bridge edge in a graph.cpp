class Solution {
   public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) {
        vector<int> visited(V, 0);
        queue<int> q;

        q.push(c);
        visited[c] = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int t = q.front();
                q.pop();

                if (t == c or t == d) {
                    vector<int> next = adj[t];
                    for (int i = 0; i < next.size(); i++) {
                        if (next[i] == c or next[i] == d) {
                            continue;
                        }
                        if (visited[next[i]] == 1) {
                            continue;
                        }
                        visited[next[i]] = 1;
                        q.push(next[i]);
                    }
                } else {
                    vector<int> next = adj[t];
                    for (auto x : next) {
                        if (visited[x] != 1) {
                            visited[x] = 1;
                            q.push(x);
                        }
                    }
                }
            }
        }

        return visited[d] == 0;
    }
};