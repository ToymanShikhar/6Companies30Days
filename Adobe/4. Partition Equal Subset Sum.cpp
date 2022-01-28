class Solution {
   public:
    bool isPossible(int nums[], int n, int curr, int sum, int dp[][101]) {
        if (sum == 0) {
            return true;
        }
        if (curr >= n) {
            return false;
        }

        if (dp[sum][curr] != -1) {
            return dp[sum][curr];
        }

        bool consider = false;
        if (nums[curr] <= sum) {
            consider = isPossible(nums, n, curr + 1, sum - nums[curr], dp);
        }

        bool notConsider = isPossible(nums, n, curr + 1, sum, dp);

        return dp[sum][curr] = consider || notConsider;
    }

    int equalPartition(int N, int nums[]) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
            return false;
        }

        sum = sum / 2;
        int dp[sum + 1][101];
        memset(dp, -1, sizeof(dp));

        return isPossible(nums, N, 0, sum, dp);
    }
};