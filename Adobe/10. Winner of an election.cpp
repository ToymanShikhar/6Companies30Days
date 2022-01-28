class Solution {
   public:
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n) {
        string ans;
        unordered_map<string, int> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]]++;
        }

        int ansN = INT_MIN;
        string ansS;

        for (auto p : m) {
            if (p.second > ansN) {
                ansN = p.second;
                ansS = p.first;
            } else if (p.second == ansN) {
                if (p.first < ansS) {
                    ansS = p.first;
                }
            }
        }

        vector<string> res;
        res.push_back(ansS);
        res.push_back(to_string(ansN));
        return res;
    }
};