string encode(string s) {
    int count = 1;
    string res;

    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            res += s[i - 1];
            res += to_string(count);
            count = 1;
        }
    }
    res += s[s.length() - 1];
    res += to_string(count);

    return res;
}