class Solution {
   public:
    /*You are required to complete this method */
    int atoi(string s) {
        bool isNeg = false;
        if (s[0] == '-') {
            isNeg = true;
            s = s.substr(1);
        }

        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!(s[i] >= '0' and s[i] <= '9')) {
                return -1;
            }
            sum = sum * 10 + (s[i] - '0');
        }

        return isNeg ? (-1 * sum) : sum;
    }
};