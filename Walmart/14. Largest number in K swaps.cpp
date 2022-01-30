class Solution {
   public:
    string ans;

    void solve(int curr, string& s, int k) {
        ans = max(ans, s);

        int n = s.length();
        if (curr >= n or k == 0) {
            return;
        }

        char maxc = s[curr];
        for (int i = curr + 1; i < n; i++) {
            if (s[i] > maxc) {
                maxc = s[i];
            }
        }

        if (s[curr] != maxc) {
            k--;
        }

        for (int i = curr; i < n; i++) {
            if (s[i] == maxc) {
                swap(s[curr], s[i]);
                solve(curr + 1, s, k);
                swap(s[curr], s[i]);
            }
        }
    }

    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k) {
        ans = str;
        solve(0, str, k);
        return ans;
    }
};