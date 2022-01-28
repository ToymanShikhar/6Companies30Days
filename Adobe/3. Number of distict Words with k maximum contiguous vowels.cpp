class Solution {
   public:
    long long M = 1000000007;

    long long solve(int curr, int k, int actualK, int n, vector<vector<long long>>& dp) {
        if (curr >= n) {
            return 1;
        }

        if (dp[curr][k] != -1) {
            return dp[curr][k];
        }

        if (k == 0) {
            return dp[curr][k] = ((21 % M) * solve(curr + 1, actualK, actualK, n, dp) % M) % M;
        }

        return dp[curr][k] = (((21 % M) * solve(curr + 1, actualK, actualK, n, dp) % M) % M + ((5 % M) * solve(curr + 1, k - 1, actualK, n, dp) % M) % M) % M;
    }

    int kvowelwords(int N, int K) {
        vector<vector<long long>> dp(1001, vector<long long>(1001, -1));
        return solve(0, K, K, N, dp) % M;
    }
};