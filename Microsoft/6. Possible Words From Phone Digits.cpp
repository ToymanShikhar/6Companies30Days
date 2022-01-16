class Solution {
   public:
    void solve(int arr[], int n, int curr, string s, vector<string>& ans, unordered_map<int, vector<char>>& m) {
        if (curr >= n) {
            ans.push_back(s);
            return;
        }

        vector<char> v = m[arr[curr]];
        for (auto x : v) {
            solve(arr, n, curr + 1, s + x, ans, m);
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N) {
        unordered_map<int, vector<char>> m;
        m[2] = vector<char>{'a', 'b', 'c'};
        m[3] = vector<char>{'d', 'e', 'f'};
        m[4] = vector<char>{'g', 'h', 'i'};
        m[5] = vector<char>{'j', 'k', 'l'};
        m[6] = vector<char>{'m', 'n', 'o'};
        m[7] = vector<char>{'p', 'q', 'r', 's'};
        m[8] = vector<char>{'t', 'u', 'v'};
        m[9] = vector<char>{'w', 'x', 'y', 'z'};

        vector<string> ans;
        solve(a, N, 0, "", ans, m);
        return ans;
    }
};