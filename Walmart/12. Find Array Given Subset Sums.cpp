class Solution {
   public:
    vector<int> res;

    void dfs(vector<int>& sums, int n) {
        while (sums.size() > 1) {
            int n = sums.size();
            int diff = sums[n - 1] - sums[n - 2];
            unordered_map<int, int> count;
            for (auto& x : sums) {
                count[x]++;
            }

            vector<int> upper;
            vector<int> lower;

            for (auto& x : sums) {
                if (count[x] == 0)
                    continue;

                count[x]--;
                count[x + diff]--;
                upper.push_back(x);
                lower.push_back(x + diff);
            }

            int flag = 1;
            for (auto& x : upper) {
                if (x == 0) {
                    res.push_back(diff);
                    sums = upper;
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                continue;

            if (flag == 1) {
                for (auto x : lower) {
                    if (x == 0) {
                        sums = lower;
                        res.push_back(-diff);
                        break;
                    }
                }
            }
        }
    }

    vector<int> recoverArray(int n, vector<int>& sums) {
        res.clear();
        sort(sums.begin(), sums.end());
        dfs(sums, n);
        return res;
    }
};