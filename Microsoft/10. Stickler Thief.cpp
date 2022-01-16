class Solution {
   public:
    int maxCost(int arr[], int n, int curr, vector<int>& dp) {
        if (curr >= n) {
            return 0;
        }

        if (dp[curr] != -1) {
            return dp[curr];
        }

        int loots = arr[curr] + maxCost(arr, n, curr + 2, dp);
        int notLoots = maxCost(arr, n, curr + 1, dp);

        return dp[curr] = max(loots, notLoots);
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n) {
        vector<int> dp(n + 1, -1);
        return maxCost(arr, n, 0, dp);
    }
};