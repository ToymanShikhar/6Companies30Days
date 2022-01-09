class Solution {
   public:
    int find(int prices[], int n, int curr, bool canBuy, int tranCount, int dp[501][2][201]) {
        if (curr >= n or tranCount <= 0) {
            return 0;
        }

        if (dp[curr][canBuy][tranCount] != -1) {
            return dp[curr][canBuy][tranCount];
        }

        int idle = find(prices, n, curr + 1, canBuy, tranCount, dp);

        if (canBuy) {
            int buy = -prices[curr] + find(prices, n, curr + 1, false, tranCount, dp);
            return dp[curr][canBuy][tranCount] = max(idle, buy);
        } else {
            int sell = prices[curr] + find(prices, n, curr + 1, true, tranCount - 1, dp);
            return dp[curr][canBuy][tranCount] = max(idle, sell);
        }
    }

    int maxProfit(int K, int N, int A[]) {
        int dp[501][2][201];
        memset(dp, -1, sizeof(dp));
        return find(A, N, 0, true, K, dp);
    }
};