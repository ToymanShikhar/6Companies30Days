class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        int ans = 0;
        while (start <= end) {
            int mid = (start + end) / 2;

            int count = 0;
            for (auto x : piles) {
                count += ceil(x / (double)mid);
            }
            if (count <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};