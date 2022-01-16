class Solution {
   public:
    int minSteps(int D) {
        int sum = 0;
        int steps = 1;
        int ans = 0;
        D = abs(D);

        while (sum < D) {
            sum += steps;
            ans++;
            steps++;
        }

        while ((sum - D) % 2 != 0) {
            sum += steps;
            ans++;
            steps++;
        }

        return ans;
    }
};