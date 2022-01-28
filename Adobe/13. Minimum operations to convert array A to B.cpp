class Solution {
   public:
    int lcs(vector<int>& v) {
        vector<int> res;
        if (v.size() == 0) {
            return 0;
        }
        res.push_back(v[0]);

        for (int i = 1; i < v.size(); i++) {
            if (v[i] > res.back()) {
                res.push_back(v[i]);
            } else {
                int id = lower_bound(res.begin(), res.end(), v[i]) - res.begin();
                res[id] = v[i];
            }
        }

        return res.size();
    }

    int minInsAndDel(int a[], int b[], int n, int m) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (binary_search(b, b + m, a[i])) {
                v.push_back(a[i]);
            }
        }

        int l = lcs(v);

        return n + m - 2 * l;
    }
};