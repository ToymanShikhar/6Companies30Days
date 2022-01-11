class Solution {
   public:
    string colName(long long int n) {
        string res;
        while (n > 0) {
            char ch = (n - 1) % 26 + 'A';
            res = ch + res;
            n = (n - 1) / 26;
        }
        return res;
    }
};