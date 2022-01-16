class Solution {
   public:
    bool isPossible(int N, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> adj(N);
        vector<int> inDeg(N, 0);
        queue<int> q;
        for (auto p : prerequisites) {
            adj[p.first].push_back(p.second);
            inDeg[p.second]++;
        }

        for (int i = 0; i < N; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        if (q.size() == 0) {
            return false;
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto x : adj[node]) {
                inDeg[x]--;
                if (inDeg[x] == 0) {
                    q.push(x);
                }
            }
        }

        return count == N;
    }
};