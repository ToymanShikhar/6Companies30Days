class Solution {
   public:
    bool canPair(vector<int> arr, int k) {
        unordered_map<int, int> m;
        for (auto x : arr) {
            int rem = ((x % k) + k) % k;
            int numToFind = rem != 0 ? k - rem : 0;

            if (m.count(numToFind)) {
                m[numToFind]--;
                if (m[numToFind] == 0) {
                    m.erase(numToFind);
                }
            } else {
                m[rem]++;
            }
        }

        if (m.size() == 0) {
            return true;
        }
        return false;
    }
};