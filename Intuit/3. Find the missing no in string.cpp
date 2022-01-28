int cti(string s) {
    long long x = 0;
    for (int i = 0; i < s.size(); i++)
        x = x * 10 + (s[i] - '0');
    return x;
}

bool find(const string& s, int i, int num) {
    string digit = to_string(num);
    int j = 0;
    while (i < s.length()) {
        if (s[i] != digit[j]) {
            return false;
        } else {
            i++;
            j++;
        }
        if (j == digit.length()) {
            return true;
        }
    }

    return false;
}

int missingNumber(const string& s) {
    for (int i = 1; i <= 6 and i < s.length(); i++) {
        int curr = cti(s.substr(0, i));
        int next = curr + 1;
        int ans = -1;
        int count = 0;

        int j = i;
        int flag = 0;
        while (j < s.length()) {
            bool isAva = find(s, j, next);
            if (isAva) {
                j = j + to_string(next).length();
                next++;
            } else {
                ans = next;
                count++;
                next++;
            }

            if (count == 2) {
                flag = 1;
                break;
            }
        }

        if (flag == 1) {
            continue;
        }

        if (count == 1) {
            return ans;
        }
    }

    return -1;
}