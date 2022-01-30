class Solution {
   public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        if (n <= 2) {
            return false;
        }

        int a = 0;
        int b = 0;

        for (int i = 1; i < n - 1; i++) {
            if (colors[i - 1] == colors[i] and colors[i] == colors[i + 1]) {
                if (colors[i] == 'A')
                    a++;
                else
                    b++;
            }
        }

        return a > b;
    }
};