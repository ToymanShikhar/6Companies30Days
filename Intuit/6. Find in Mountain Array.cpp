class Solution {
   public:
    int findInMountainArray(int target, MountainArray &mArr) {
        int left = 1;
        int right = mArr.length() - 2;

        int peak = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int a = mArr.get(mid - 1);
            int b = mArr.get(mid);
            int c = mArr.get(mid + 1);

            if (a < b and b < c) {
                left = mid + 1;
            } else if (a > b and b > c) {
                right = mid - 1;
            } else {
                peak = mid;
                break;
            }
        }

        left = 0;
        right = peak;
        while (left <= right) {
            int mid = (left + right) / 2;
            int val = mArr.get(mid);
            if (val == target) {
                return mid;
            } else if (target < val) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        left = peak;
        right = mArr.length() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int val = mArr.get(mid);
            if (val == target) {
                return mid;
            } else if (target < val) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};