class Solution {
   public:
    void solve(int n, int open, int close, string curr, vector<string>& res) {
        if (open == n and close == n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            solve(n, open + 1, close, curr + '(', res);
        }
        if (open > close) {
            solve(n, open, close + 1, curr + ')', res);
        }

        return;
    }

    vector<string> AllParenthesis(int n) {
        vector<string> res;
        solve(n, 0, 0, "", res);
        return res;
    }
};