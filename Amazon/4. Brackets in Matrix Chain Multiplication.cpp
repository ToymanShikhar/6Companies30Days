class Solution {
   public:
    pair<int, string> solve(int nums[], int start, int end, pair<int, string> dp[26][26]) {
        if (end == start + 1) {
            char ch = start + 65;
            string temp;
            temp += ch;
            return {0, temp};
        }

        if (dp[start][end].first != -1) {
            return dp[start][end];
        }

        pair<int, string> ans;
        ans.first = INT_MAX;
        for (int i = start + 1; i < end; i++) {
            pair<int, string> left = solve(nums, start, i, dp);
            pair<int, string> right = solve(nums, i, end, dp);

            int cost = left.first + right.first + nums[start] * nums[i] * nums[end];
            string s = "(" + left.second + right.second + ")";

            if (cost < ans.first) {
                ans = {cost, s};
            }
        }

        return dp[start][end] = ans;
    }

    string matrixChainOrder(int p[], int n) {
        pair<int, string> dp[26][26];
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dp[i][j] = {-1, ""};
            }
        }

        pair<int, string> ans = solve(p, 0, n - 1, dp);
        return ans.second;
    }
};