class Solution {
   public:
    long long M = 1000000007;

    long long solve(long long curr, long long p, long long sum, vector<vector<long long>>& dp) {
        if (sum == 0) {
            return 1;
        }

        if (curr > ceil(pow(sum, 1.0 / p))) {
            return 0;
        }

        if (dp[curr][sum] != -1) {
            return dp[curr][sum];
        }

        long long ans = 0;
        if (pow(curr, p) <= sum) {
            ans = (ans % M + solve(curr + 1, p, sum - pow(curr, p), dp) % M) % M;
        }
        ans = (ans % M + solve(curr + 1, p, sum, dp) % M) % M;

        return dp[curr][sum] = ans % M;
    }

    long long numOfWays(long long n, long long x) {
        vector<vector<long long>> dp(1005, vector<long long>(1005, -1));
        return solve(1, x, n, dp) % M;
    }
};