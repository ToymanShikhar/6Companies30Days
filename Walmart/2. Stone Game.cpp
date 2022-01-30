class Solution {
   public:
    int maxPoints(vector<int>& piles, int i, int j, int dp[501][501], vector<int>& sum) {
        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int op1 = maxPoints(piles, i + 1, j, dp, sum);
        int op2 = maxPoints(piles, i, j - 1, dp, sum);

        int ans = sum[j] - sum[i] + piles[i] - min(op1, op2);

        return dp[i][j] = ans;
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> sumall(n);
        sumall[0] = piles[0];
        for (int i = 1; i < n; i++) {
            sumall[i] = sumall[i - 1] + piles[i];
        }

        int dp[501][501];
        memset(dp, -1, sizeof(dp));

        int alice = maxPoints(piles, 0, piles.size() - 1, dp, sumall);
        if (alice > (sumall[n - 1] / 2)) {
            return true;
        } else {
            return false;
        }
    }
};