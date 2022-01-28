class Solution {
   public:
    int shipWithinDays(vector<int>& arr, int D) {
        int N = arr.size();

        int left = INT_MIN;
        int right = 0;
        for (int i = 0; i < N; i++) {
            left = max(left, arr[i]);
            right += arr[i];
        }

        int ans = INT_MAX;
        while (left <= right) {
            int mid = (left + right) / 2;

            int day = 0;
            int sum = 0;
            for (int i = 0; i < N; i++) {
                sum += arr[i];
                if (sum == mid) {
                    day++;
                    sum = 0;
                } else if (sum > mid) {
                    day++;
                    sum = arr[i];
                }
            }
            if (sum > 0) {
                day++;
            }

            if (day > D) {
                left = mid + 1;
            } else {
                ans = min(ans, mid);
                right = mid - 1;
            }
        }

        return ans;
    }
};