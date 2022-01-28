class Solution {
   public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                int dist = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
                m[dist]++;
            }

            for (auto p : m) {
                ans += p.second * (p.second - 1);
            }

            m.clear();
        }

        return ans;
    }
};