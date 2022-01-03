class Solution {
   public:
    int solve(string str, int curr, int dp[10001]) {
        if (curr >= str.length()) {
            return 1;
        }

        if (dp[curr] != -1) {
            return dp[curr];
        }

        int ans = 0;
        //single number
        if (str[curr] >= '1' and str[curr] <= '9') {
            ans = (ans % 1000000007 + solve(str, curr + 1, dp) % 1000000007) % 1000000007;
        }

        //two number
        if (curr + 1 < str.length()) {
            int num = str[curr] - '0';
            num = num * 10 + (str[curr + 1] - '0');

            if (num >= 10 and num <= 26) {
                ans = (ans % 1000000007 + solve(str, curr + 2, dp) % 1000000007) % 1000000007;
            }
        }

        return dp[curr] = ans % 1000000007;
    }

    int CountWays(string str) {
        int dp[10001];
        memset(dp, -1, sizeof(dp));
        return solve(str, 0, dp);
    }
};