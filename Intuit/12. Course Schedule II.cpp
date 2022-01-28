class Solution {
   public:
    vector<int> res;
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(N);
        vector<int> inDeg(N, 0);
        for (auto v : prerequisites) {
            adj[v[0]].push_back(v[1]);
            inDeg[v[1]]++;
        }
        res.clear();
        queue<int> q;

        for (int i = 0; i < N; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            res.push_back(node);

            for (auto x : adj[node]) {
                inDeg[x]--;
                if (inDeg[x] == 0) {
                    q.push(x);
                }
            }
        }

        if (count != N) {
            return vector<int>();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};