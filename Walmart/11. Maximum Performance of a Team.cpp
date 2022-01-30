class Solution {
   public:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> nums(n);
        for (int i = 0; i < n; i++) {
            nums[i] = {speed[i], efficiency[i]};
        }

        sort(nums.begin(), nums.end(), compare);
        priority_queue<int, vector<int>, greater<int>> pq;

        long long res = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int sp = nums[i].first;
            int ef = nums[i].second;

            sum += sp;
            pq.push(sp);
            if (pq.size() > k) {
                int t = pq.top();
                pq.pop();
                sum -= t;
            }

            res = max(res, sum * ef);
        }

        return res % 1000000007;
    }
};