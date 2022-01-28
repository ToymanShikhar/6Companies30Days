class Solution {
   public:
    bool isPossible(int lim, vector<int>& nums, int m) {
        int sum = 0;
        int sz = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > lim) {
                sz++;
                sum = nums[i];
            }
        }

        if (sz <= m) {
            return true;
        }

        return false;
    }

    int splitArray(vector<int>& nums, int m) {
        int left = INT_MIN;
        int right = 0;
        for (auto x : nums) {
            left = max(left, x);
            right += x;
        }

        int ans = INT_MAX;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (isPossible(mid, nums, m)) {
                ans = min(ans, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};