class Solution {
   public:
    string nextPalin(string str) {
        int n = str.length();
        string s = str.substr(0, n / 2);

        int flag = 0;
        for (int i = s.length() - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                char ch = s[i + 1];
                int idx = i + 1;
                for (int j = i + 1; j < s.length(); j++) {
                    if (s[j] > s[i] and s[j] < ch) {
                        ch = s[j];
                        idx = j;
                    }
                }
                swap(s[i], s[idx]);
                sort(s.begin() + i + 1, s.end());
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return "-1";
        }

        string r = s;
        reverse(r.begin(), r.end());

        if (n % 2 != 0) {
            s += str[n / 2];
        }
        s += r;

        return s;
    }
};