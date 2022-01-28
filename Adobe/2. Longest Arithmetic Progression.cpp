class Solution {
   public:
    int lengthOfLongestAP(int nums[], int n) {
        int x = nums[n - 1] - nums[0];
        vector<vector<int>> dp(x + 1, vector<int>(n + 1, 1));
        int res = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                dp[diff][i] = max(1 + dp[diff][j], dp[diff][i]);
                res = max(res, dp[diff][i]);
            }
        }

        return res;
    }
};