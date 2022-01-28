class Solution {
   public:
    string amendSentence(string s) {
        string res;
        res += tolower(s[0]);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] >= 65 and s[i] <= 90) {
                res += ' ';
                res += tolower(s[i]);
                continue;
            }

            res += s[i];
        }

        return res;
    }
};