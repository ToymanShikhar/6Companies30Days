class Solution {
   public:
    int divide(long long dd, long long ds) {
        long long ans = 0;
        long long sign = 1;
        if (dd < 0) {
            sign *= -1;
        }
        if (ds < 0) {
            sign *= -1;
        }

        dd = abs(dd);
        ds = abs(ds);

        while (dd >= ds) {
            long long temp = ds;
            long long m = 1;
            while (dd >= temp) {
                temp = temp << 1;
                m = m << 1;
            }

            temp = temp >> 1;
            m = m >> 1;

            ans += m;
            dd -= temp;
        }

        ans = sign == -1 ? -ans : ans;

        if (ans > INT_MAX)
            return INT_MAX;
        else if (ans < INT_MIN)
            return INT_MIN;
        return ans;
    }
};