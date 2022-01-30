class Solution {
   public:
    long long m = 1000000007;
    //You need to complete this fucntion

    long long solve(long long a, long long b) {
        if (b == 0) {
            return 1;
        }

        if (b % 2 == 0) {
            long long temp = solve(a, b / 2) % m;
            return ((temp % m) * (temp % m)) % m;
        } else {
            return ((a % m) * (solve(a, b - 1) % m)) % m;
        }
    }

    long long power(int N, int R) {
        return solve(N, R) % m;
    }
};