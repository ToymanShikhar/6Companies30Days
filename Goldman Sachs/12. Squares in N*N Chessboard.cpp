// Approach 1 ---> T=O(n)
class Solution {
   public:
    long long squaresInChessBoard(long long N) {
        long long res = 0;
        for (int i = 1; i <= N; i++) {
            long long num = N - i + 1;
            res += num * num;
        }

        return res;
    }
};

// Approach 2 ---> T=O(1)
class Solution {
   public:
    long long squaresInChessBoard(long long N) {
        return N * (N + 1) * (2 * N + 1) / 6;
    }
};