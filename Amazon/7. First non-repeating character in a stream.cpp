class Solution {
   public:
    string FirstNonRepeating(string s) {
        queue<char> q;
        int arr[26]{0};

        string res;
        for (int i = 0; i < s.length(); i++) {
            int idx = s[i] - 'a';
            if (arr[idx] == 0) {
                q.push(s[i]);
            }
            arr[idx]++;
            while (!q.empty() and arr[q.front() - 'a'] != 1) {
                q.pop();
            }
            if (q.empty()) {
                res += '#';
            } else {
                res += q.front();
            }
        }

        return res;
    }
};