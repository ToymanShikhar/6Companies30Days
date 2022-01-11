class Solution {
   public:
    //Function to count number of ways to reach the nth stair
    //when order does not matter.
    long long solve(int curr, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) {
            return 1;
        }
        if (curr >= nums.size()) {
            return 0;
        }

        if (dp[target][curr] != -1) {
            return dp[target][curr];
        }

        long long ans = 0;
        if (nums[curr] <= target) {
            ans += solve(curr, nums, target - nums[curr], dp);
        }
        ans += solve(curr + 1, nums, target, dp);

        return dp[target][curr] = ans;
    }

    long long countWays(int m) {
        vector<vector<int>> dp(m + 1, vector<int>(3, -1));
        vector<int> v{1, 2};
        return solve(0, v, m, dp);
    }
};