class Solution {
   public:
    int countSubArrayProductLessThanK(const vector<int>& nums, int n, long long k) {
        int i = 0;
        int j = 0;
        int res = 0;
        long long product = 1;

        while (j < n) {
            product *= nums[j];
            if (product < k) {
                res += (j - i + 1);
            }
            if (product >= k) {
                while (i < j and product >= k) {
                    product /= nums[i];
                    i++;
                }
                if (product < k) {
                    res += (j - i + 1);
                }
            }
            j++;
        }

        return res;
    }
};