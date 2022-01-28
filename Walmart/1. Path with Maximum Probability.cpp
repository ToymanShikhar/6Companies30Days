class compare {
   public:
    bool operator()(pair<int, double>& a, pair<int, double>& b) {
        return a.second < b.second;
    }
};

class Solution {
   public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<int, double>, vector<pair<int, double>>, compare> pq;
        pq.push({start, 1.0});
        vector<bool> visited(n, false);

        while (!pq.empty()) {
            pair<int, double> t = pq.top();
            pq.pop();
            int node = t.first;
            double prob = t.second;

            visited[node] = true;
            if (node == end) {
                return prob;
            }

            for (auto p : adj[node]) {
                if (!visited[p.first]) {
                    pq.push({p.first, prob * p.second});
                }
            }
        }

        return 0;
    }
};