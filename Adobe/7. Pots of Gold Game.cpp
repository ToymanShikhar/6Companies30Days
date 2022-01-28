class Solution {
   public:
    int solve(vector<int>& nums, int start, int end, vector<int>& sum, vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }

        if (dp[start][end] != -1) {
            return dp[start][end];
        }

        int front = solve(nums, start + 1, end, sum, dp);
        int back = solve(nums, start, end - 1, sum, dp);

        return dp[start][end] = sum[end] - sum[start] + nums[start] - min(front, back);
    }

    int maxCoins(vector<int>& A, int n) {
        vector<int> sum;
        int curr = 0;
        for (auto x : A) {
            curr += x;
            sum.push_back(curr);
        }

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(A, 0, n - 1, sum, dp);
    }
};