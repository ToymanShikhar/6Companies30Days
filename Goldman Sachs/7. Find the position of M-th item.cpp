class Solution {
   public:
    int findPosition(int N, int M, int K) {
        int num = M % N;
        if (num == 0) {
            num = N;
        }

        int start = K % N;
        if (start == 0) {
            start = N;
        }

        int ans = start + num - 1;
        ans %= N;
        if (ans == 0) {
            ans = N;
        }

        return ans;
    }
};