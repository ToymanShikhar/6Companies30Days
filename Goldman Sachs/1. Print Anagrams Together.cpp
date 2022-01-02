class Solution {
   public:
    vector<vector<string>> Anagrams(vector<string>& string_list) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;

        for (auto s : string_list) {
            string sNew = s;
            sort(sNew.begin(), sNew.end());
            m[sNew].push_back(s);
        }

        for (auto p : m) {
            res.push_back(p.second);
        }

        return res;
    }
};